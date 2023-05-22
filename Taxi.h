#pragma once
#include <string>
#include <vector>
#include "Route.h"
#include <iostream>
class Taxi {
public:
	Taxi();

    // Getters
    long getId() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYearOfProduction() const;
    int getNumberOfSeats() const;
    int getLoadCapacity() const;
    double getFuelConsumption() const;
    Route* getRoute() const; //prob crash

    // Setters
    void setBrand(const std::string& newBrand);
    void setModel(const std::string& newModel);
    void setYearOfProduction(int newYear);
    void setNumberOfSeats(int newSeats);
    void setLoadCapacity(int newCapacity);
    void setFuelConsumption(double newConsumption);
    void setRoute(Route* newRoute);
    const long generateId() const;
    friend std::ostream& operator<<(std::ostream& os, const Taxi& taxi);

private:
    static long counterId;
    long id;

    std::string brand;
    std::string model;
    int yearOfProduction;
    int numberOfSeats;
    int loadCapacity;
    double fuelConsumption;
    Route* route;

};