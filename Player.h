#ifndef PLAYER_H_INCLUDE
#define PLAYER_H_INCLUDE

class Player {
public:
	Player(int posX = 0, int posY = 0) : positionX(posX), positionY(posY){};
	void initializePlayer(int width, int height);
	void move(int key, int width, int height);

	inline int getPosX() {return positionX;}
	inline int getPosY() {return positionY;}

private:
	int positionX;
	int positionY;

	static const int MOVE_UP = 119;
	static const int MOVE_DOWN = 115;
	static const int MOVE_RIGHT = 100;
	static const int MOVE_LEFT = 97;
};

#endif