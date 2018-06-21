#ifndef CITY_H
#define CITY_H

//#include "Map.h"
#include "allegro/allegro.h"
#include <vector>
using std::vector;

class City {
public:
	static vector<Sprite> sprites;

	unsigned pop;
	Coos position;
	Gold production;
	
	City(unsigned population, Coos pos, Gold prod){
		pop = population;
		position = pos;
		production = prod;
	}
	
	void draw(Allegro* allegro){
		unsigned n_sprite = 0;
		if(pop <= 1000){
			n_sprite = 0;
		} else if(1000 < pop && pop <= 5000){
			n_sprite = 1;
		} else if(5000 < pop && pop <= 30000){
			n_sprite = 2;
		} else {
			n_sprite = 3;
		}
		sprites.at(n_sprite).drawSprite(position.x, position.y, (n_sprite+1)*20, (n_sprite+1)*20, true);
	}
};

#endif // CITY_H
