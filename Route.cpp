#include "Route.h"
#include <iostream>
Route::Route(){
	this->id = generateId();
	length = 0;
	neededFuel = 0;
	dailyTrips = 0;
	std::cout << "Route created with id" <<std::endl;
}

const void Route::addStopsToRoute(Stop* stop) {	
	if (stops.empty()){
		stops.push_back(stop);
	}
	else {

		Stop* lastStop = stops.at(stops.size() - 1);
		int distance = lastStop->calculateDistance(*stop);
		this->length += distance;
		this->neededFuel = calculateFuel(fuelPrice);
		stops.push_back(stop);
	}
}

int Route::calculateFuel(int priceOfFuel) {
	return length / priceOfFuel;
}

// Getters
const std::vector<Stop*>& Route::getStops() const {
	return stops;
}

int Route::getDailyTrips() const {
	return dailyTrips;
}

int Route::getNeededFuel() const {
	return neededFuel;
}

int Route::getLength() const {
	return length;
}

int Route::getId() const{ //the address is saved correctly but the id is not being saved
	return id;
}

// Setters
void Route::setStops(const std::vector<Stop*>& newStops) {
	stops = newStops;
}

void Route::setDailyTrips(int newDailyTrips) {
	dailyTrips = newDailyTrips;
}

void Route::setNeededFuel(int newNeededFuel) {
	neededFuel = newNeededFuel;
}

void Route::setLength(int newLength) {
	length = newLength;
}

long Route::counterId = 0;

double Route::fuelPrice = 2.20;

const long Route::generateId() const{
	return ++counterId;
}

std::ostream& operator<<(std::ostream& os, const Route& route)
{

  os << "Id of route is :" << route.id << "\n"
	 <<"The route is traversed :" << route.dailyTrips <<" times" << "\n"
	 << "Needed fuel for route is :" << route.neededFuel << "\n"
	 << "Length is :" << route.length << std::endl;

	return os;

}
