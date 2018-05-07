#ifndef CITY_H
#define CITY_H

//#include "Map.h"

class City {
private:
	unsigned pop;
	Coos position;
	Gold production;
public:
	
	City(unsigned population, Coos pos, Gold prod){
		pop = population;
		position = pos;
		production = prod;
	}
};

#endif // CITY_H
