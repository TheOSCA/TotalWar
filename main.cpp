#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>

#include "Ressources.h"
#include "Map.h"
#include "City.h"

using namespace std;

int main(int argc, char** args){
	City test(100, Coos(10, 10), Gold(100));
	
	test.production += 10;
	
	cout << test.production;
	
	cin.get();
}