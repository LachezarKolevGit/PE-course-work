#include <stdlib.h>
#include <iostream> 
#include "Stop.h"
#include "Taxi.h"
#include "Map.h"
#include <fstream>
void printTaxis(const std::vector<Taxi*>&);
void printRoutes(Map&);
void printStops(const std::vector<Stop*>&);
void setRouteToTaxi(const std::vector<Taxi*>& , Map& );
void addStopsToRoute(Map& , const std::vector<Stop*>& );
void viewRouteStops(Map& );
void writeToFile(const Map& );

void menu() {
	std::cout << "1.Create taxi" <<"\n";
	std::cout << "2.Create stop" << "\n";
	std::cout << "3.Create route" << "\n";
	std::cout << "4.View taxis" << "\n";
	std::cout << "5.View routes" << "\n";
	std::cout << "6.View stops" << "\n";
	std::cout << "7.Add stops to route" << "\n";
	std::cout << "8.Assign taxi to route" << "\n";
	std::cout << "9.View stops of a route " << "\n";
	std::cout << "10.Save in file" << "\n";
	std::cout << "11.Exit" << "\n";
	std::cout << "Choose an option" << std::endl;
}
int main() {
	std::vector<Taxi*> taxis;
	std::vector<Stop*> stops;
	Map map;
	do {
	menu();
	int choice = 0;
	std::cin >> choice;
	while (choice > 11 || choice < 1)
	{
		std::cout << "Invalid menu options"<<"\n";
		std::cout << "Enter again"<<std::endl;
			std::cin >> choice;
	}
	switch (choice)
	{
	case 1: {
		Taxi* taxi = new Taxi();
		std::cout << taxi;
		taxis.push_back(taxi);
		break;
	}
	case 2: {
		Stop* stop = new Stop();
		std::cout << stop;
		stops.push_back(stop);
		break;
	}
	case 3: {
		Route* route = new Route();
		std::cout << route;
		map.addRoute(route);
		break;
	}
	case 4:
		printTaxis(taxis);
		break;
	case 5: {
		printRoutes(map);
		break;
	}
	case 6: {
		printStops(stops);
		break;
	}
	case 7: {
		try {
			addStopsToRoute(map, stops);
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		break;
	}
	case 8: {
		try {
			setRouteToTaxi(taxis, map);
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}
		
		break;
	}
	case 9: {
		try {
			viewRouteStops(map);
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}

		break;
	}
	case 10: {
		try {
			writeToFile(map);
		}
		catch (std::invalid_argument& e) {
			std::cerr << e.what() << std::endl;
		}

		break;
	}
	case 11: {
		return 0;
		break;
	}
	default:
		break;
	}


	} while (1);
return 0;
}
void printTaxis(const std::vector<Taxi*>& taxis) {
	std::cout << "-------------------------" << std::endl;
	std::cout << "List of taxis :" << std::endl;
	for (const Taxi* taxi : taxis) {
		std::cout << *taxi;
	}
	std::cout << "-------------------------" << std::endl;


}
void printRoutes(Map& map) {
	std::cout << "-------------------------" << std::endl;
	std::cout << "List of routes :" << std::endl;
	for (const Route* route : map.getAllRoutes()) {
		std::cout << *route;
	}
	std::cout << "-------------------------" << std::endl;
}

void printStops(const std::vector<Stop*>& stops) {
	std::cout << "-------------------------" << std::endl;
	std::cout << "List of stops :" << std::endl;
	
	for (const Stop* stop : stops) {
		std::cout << *stop;
	}
	std::cout << "-------------------------" << std::endl;
}

void addStopsToRoute(Map& map, const std::vector<Stop*>& stops) {
	if (map.getAllRoutes().empty() || stops.empty()) {
		throw std::invalid_argument("THERE AREN'T ANY ROUTES OR STOPS");
	}

	std::cout << "Enter id of route";
	long routeId;
	std::cin >> routeId;
	while (routeId < 1)
	{
		std::cout << "Invalid route id" << "\n";
		std::cout << "Enter again" << std::endl;
		std::cin >> routeId;
	}

	Route* route = map.getRoute(routeId - 1);

	std::cout << "Enter id of a stop";
	long stopId;
	std::cin >> stopId;
	while (stopId < 1)
	{
		std::cout << "Invalid stop id" << "\n";
		std::cout << "Enter again" << std::endl;
		std::cin >> routeId;
	}
	Stop* stopPointer = stops.at(stopId - 1);

	route->addStopsToRoute(stopPointer);
}

void setRouteToTaxi(const std::vector<Taxi*>& taxis, Map& map) {
	if (map.getAllRoutes().empty() || taxis.empty()) {
		throw std::invalid_argument("THERE AREN'T ANY TAXIS OR ROUTES");
	}

	std::cout << "Enter id of taxi";
	long taxiId;
	std::cin >> taxiId;
	while (taxiId < 1)
	{
		std::cout << "Invalid taxi id" << "\n";
		std::cout << "Enter again" << std::endl;
		std::cin >> taxiId;
	}
	Taxi* taxi = taxis.at(taxiId - 1);
	std::cout << "nee";
	fflush;
	std::cout << "Enter id of route";
	long routeId;
	std::cin >> routeId;
	while (routeId < 1)
	{
		std::cout << "Invalid route id" << "\n";
		std::cout << "Enter again" << std::endl;
		std::cin >> routeId;
	}

	Route* route = map.getRoute(routeId - 1);
	std::cout << route;
	taxi->setRoute(route); 
}
void viewRouteStops(Map& map) {
	std::cout << "Enter id of route";
	long routeId;
	std::cin >> routeId;
	while (routeId < 1)
	{
		std::cout << "Invalid route id" << "\n";
		std::cout << "Enter again" << std::endl;
		std::cin >> routeId;
	}
	Route* route = map.getRoute(routeId - 1);
	std::vector<Stop*> stops = route->getStops();
	std::cout << "----------------------------" << std::endl;
	std::cout << "Stops of the route are:"<<std::endl;
	for (Stop* stop :stops)
	{
		std::cout << *stop;
	}
	std::cout << "----------------------------" << std::endl;
}
void writeToFile(const Map& map) {

	std::ofstream file("save.txt");
	if (file.is_open())
	{
		std::cout << "Saving data in file"<<std::endl;
		for (const Route* route : map.getAllRoutes()) {
			file << *route;
		}


		file.close();
	}

	return;

}
