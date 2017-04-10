#ifndef GAME_H_INCLUDE
#define GAME_H_INCLUDE

#include <Player.h>
#include <Map.h>

class Game {
public:
	Game(int frameRate = 17, int wdt = 8, int hgt = 6, int shouldR = 0) 
	: gameFrameRate(frameRate), width(wdt), height(hgt), shouldReturn(shouldR){};
	void initializeGame();
	void play();
	void draw();
	int getPressedKey();
	char getCharPressedKey();
	void identifyKeypressed();

private:
	Player player;
	Map map;
	int gameFrameRate;
	int width;
	int height;
	int shouldReturn;
};

#endif