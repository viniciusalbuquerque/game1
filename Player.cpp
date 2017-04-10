#include <Player.h>
#include <iostream>
using std::cout;

void Player::initializePlayer(int width, int height) {
	positionX = height - 1;
}

void Player::move(int key, int width, int height) {
	switch (key) {
		case MOVE_UP:
			if(positionX > 0) {
				positionX--;
			}
			break;
		case MOVE_DOWN:
			if(positionX < height - 1) {
				positionX++;
			}
			break;
		case MOVE_RIGHT:
			if(positionY < width - 1) {
				positionY++;
			}
			break;
		case MOVE_LEFT:
			if(positionY > 0) {
				positionY--;
			}
			break;
	}
}