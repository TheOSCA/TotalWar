#ifndef MAP_H
#define MAP_H

#include <cmath>

class Coos {
	int x;
	int y;
public:
	Coos(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
	
	float getDistance(Coos const& c2){
		return sqrt(pow((x-c2.x),2) + pow((y-c2.y),2));
	}
};

class Map {
public:
	

};

#endif // MAP_H
