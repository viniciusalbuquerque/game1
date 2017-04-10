#include <Game.h>
#include <Player.h>
#include <Map.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
using std::cout;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;
using namespace std;

char Game::getCharPressedKey() {

	struct termios old_tio, new_tio;
    unsigned char keyPressedInt;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    keyPressedInt = getchar();
    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    return keyPressedInt;
}

int Game::getPressedKey() {

	struct termios old_tio, new_tio;
    unsigned int keyPressedInt;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    keyPressedInt = getchar();
    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    return keyPressedInt;
}

void Game::draw() {
	system("clear");
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(i == player.getPosX() && j == player.getPosY()) {
				cout << "|";
			} else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void Game::identifyKeypressed() {
	while(true) {
		int key = getPressedKey();
		if (key == 27) {
			cout << "exit\n";
			shouldReturn = -1;
			return;
		}
		player.move(key, width, height);	
	}
}

void Game::play() {
	thread keyPressThread(&Game::identifyKeypressed, this);
	keyPressThread.detach();

	while(true) {
		if(shouldReturn == -1) {
			return;
		}
		draw();	
		sleep_for(milliseconds(gameFrameRate));
	}
}

void Game::initializeGame() {
	player.initializePlayer(width, height);
	map.initializeMap(width, height, &player);
	play();
}