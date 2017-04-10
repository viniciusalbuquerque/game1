#ifndef MAP_H_INCLUDE
#define MAP_H_INCLUDE

#include <Object.h>
#include <vector>
using std::vector;	

class Map {	
public:
	Map(int width = 100, int height = 100) : totalWidth(width), totalHeight(height){};
	void initializeMap(int windowWid, int windowHei);
	void initializeObjects();

private:
	int totalWidth;
	int totalHeight;

	int windowWidth;
	int windowHeight;


	vector<Object> objects;

};

#endif