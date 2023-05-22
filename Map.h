#pragma once
#include "Route.h"
#include <vector>
class Map {
public:
	Map();
	Route* getRoute(int routeIndex);
	void addRoute(Route* route);
	const std::vector<Route*> getAllRoutes() const;
	
private:
	std::vector<Route*> routes;  
};