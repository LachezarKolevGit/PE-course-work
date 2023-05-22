#include "Map.h"
#include <iostream>
#include <stdexcept>

Map::Map() {
}

 Route* Map::getRoute(int roudeIndex){
return routes.at(roudeIndex);
}

void Map::addRoute(Route* route){
	routes.push_back(route);
}

const std::vector<Route*> Map::getAllRoutes() const{
	return routes;
}



