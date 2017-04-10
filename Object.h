#ifndef OBJECT_H_INCLUDE
#define OBJECT_H_INCLUDE

class Object {
public:
	Object(int posx = 0, int posy = 0) : positionX(posx), positionY(posy){};
	void initializeObject(int posX, int posy);

private:
	int positionX;
	int positionY;
};

#endif