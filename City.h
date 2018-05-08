#ifndef CITY_H
#define CITY_H

//#include "Map.h"

class City {
public:
	unsigned pop;
	Coos position;
	Gold production;
	
	City(unsigned population, Coos pos, Gold prod){
		pop = population;
		position = pos;
		production = prod;
	}
};

#endif // CITY_H
