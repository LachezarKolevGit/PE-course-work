#include "Stop.h"
#include <iostream>
Stop::Stop() {
	this->id = generateId();
	std::cout << "Enter coordinate X\n";
	std::cin >> coordinateX;
	while (std::cin.fail()) {
		std::cout << "Invalid input. Please enter an integer." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
		std::cout << "Enter coordinate X\n";
		std::cin >> coordinateX;
	}
	std::cout << "Enter coordinate Y\n";
	std::cin >> coordinateY;
	while (std::cin.fail()) {
		std::cout << "Invalid input. Please enter an integer." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter coordinate Y\n";
		std::cin >> coordinateY;
	}

	std::cout << "New stop created with id " << this->id << std::endl;
}

long Stop::getId() const {
	return id;
}

int Stop::getCoordinateX() const {
	return coordinateX;
}

int Stop::getCoordinateY() const {
	return coordinateY;
}

void Stop::setCoordinateX(int coordinateX) {
	this->coordinateX = coordinateX;
}

void Stop::setCoordinateY(int coordinateY) {
	this->coordinateY = coordinateY;
}

int Stop::calculateDistance(Stop& stop) const{
	return sqrt(pow((stop.getCoordinateX() - this->coordinateX), 2)
		+ pow(((stop.getCoordinateY() - this->coordinateY)), 2));
}

int Stop::counterId = 0;

const int Stop::generateId() const{
	return ++counterId;
}


std::ostream& operator<<(std::ostream& os, const Stop& stop) {
	os << "Id of stop is :" << stop.id << "\n";
	std::cout << "Coordinate X is :" << stop.coordinateX << "\n";
	std::cout << "Coordinate Y is :" << stop.coordinateY << std::endl;
	return os;
}
