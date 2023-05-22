#include "Taxi.h"
#include <stdlib.h>
#include <iostream>
Taxi::Taxi() {
    this->id = generateId();

    std::cout << "Enter brand" << std::endl;
	std::cin>>brand;
    std::cout << "Enter model" << std::endl;
    std::cin >> model;
    std::cout << "Enter year of production" << std::endl;
    std::cin >> yearOfProduction;
    while (yearOfProduction > 2023 || yearOfProduction < 1900) {
        std::cout << "Invalid input. Please enter valid years." << std::endl;
        std::cout << "Enter year of production" << std::endl;
        std::cin >> yearOfProduction;
    }
    while (std::cin.fail()) {
        std::cout << "Invalid input. Please enter an integer for the years." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter year of production" << std::endl;
        std::cin >> yearOfProduction;
    }
    std::cout << "Enter number of seats" << std::endl;
    std::cin >> numberOfSeats;
    while (numberOfSeats > 5 || numberOfSeats < 1) {
        std::cout << "Invalid input. Please enter valid number of seats." << std::endl;
        std::cout << "Enter number of seats" << std::endl;
        std::cin >> numberOfSeats;
    }

    std::cout << "Enter load capacity" << std::endl;
    std::cin >> loadCapacity;
    while (loadCapacity < 0) {
        std::cout << "Invalid input. Please enter valid load capacity." << std::endl;
        std::cout << "Enter load capacity" << std::endl;
        std::cin >> loadCapacity;
    }


    std::cout << "Enter fuel consumption" << std::endl;
    std::cin >> fuelConsumption;
    while (fuelConsumption > 80 || fuelConsumption < 0) {
        std::cout << "Invalid input. Please enter valid fuelConsumption." << std::endl;
        std::cout << "Enter fuel consumption" << std::endl;
        std::cin >> fuelConsumption;
    }

	std::cout << "Taxi created";

    this->route = nullptr;
}

// Getters
long Taxi::getId() const {
    return id;
}

std::string Taxi::getBrand() const {
    return brand;
}

std::string Taxi::getModel() const {
    return model;
}

int Taxi::getYearOfProduction() const {
    return yearOfProduction;
}

int Taxi::getNumberOfSeats() const {
    return numberOfSeats;
}

int Taxi::getLoadCapacity() const {
    return loadCapacity;
}

double Taxi::getFuelConsumption() const {
    return fuelConsumption;
}

Route* Taxi::getRoute() const {
    return route;
}

// Setters
void Taxi::setBrand(const std::string& newBrand) {
    brand = newBrand;
}

void Taxi::setModel(const std::string& newModel) {
    model = newModel;
}

void Taxi::setYearOfProduction(int newYear) {
    yearOfProduction = newYear;
}

void Taxi::setNumberOfSeats(int newSeats) {
    numberOfSeats = newSeats;
}

void Taxi::setLoadCapacity(int newCapacity) {
    loadCapacity = newCapacity;
}

void Taxi::setFuelConsumption(double newConsumption) {
    fuelConsumption = newConsumption;
}

void Taxi::setRoute(Route* newRoute){ //successfully set address pointer
   route = newRoute;
}

long Taxi::counterId = 0;

const long Taxi::generateId() const {
    return ++counterId;
}

std::ostream& operator<<(std::ostream& os, const Taxi& taxi){
    os << "Id: " << taxi.id << "\n"
        << "Brand is " << taxi.brand << "\n" <<
        "Model is " << taxi.model << "\n" <<
        "Year of production is " << taxi.yearOfProduction << "\n" <<
        "Number of seats is " << taxi.numberOfSeats << "\n" <<
        "Load capacity is " << taxi.loadCapacity << "\n" <<
        "Fuel consumption is " << taxi.fuelConsumption <<"\n"
        "Assigned route id is: "<< std::endl;

         if (taxi.route != nullptr){
             os<< taxi.route->getId() <<std::endl;
         } else {
            os<<"null"<< std::endl;
         }
      
         

    return os;
}


