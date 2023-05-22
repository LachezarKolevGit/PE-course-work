#pragma once
#include <vector>
#include "Stop.h"
class Route{
public:
	Route();
	const void addStopsToRoute(Stop* destination);
	int calculateFuel(int priceOfFuel);

	// Getters
	const std::vector<Stop*>& getStops() const;
	int getDailyTrips() const;
	int getNeededFuel() const;
	int getLength() const;
	int getId() const;

	// Setters
	void setStops(const std::vector<Stop*>& newStops);
	void setDailyTrips(int newDailyTrips);
	void setNeededFuel(int newNeededFuel);
	void setLength(int newLength);
	const long generateId()const;
	friend std::ostream& operator<<(std::ostream& os, const Route& route);
	
private:
	static double fuelPrice;
	static long counterId;
	long id;
	std::vector<Stop*> stops;
	int dailyTrips;
	int neededFuel;
	int length;
};

