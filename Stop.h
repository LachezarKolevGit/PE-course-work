#pragma once
#include <iostream>
class Stop {
public:
	Stop();
	long getId() const;
	int getCoordinateX() const;
	int getCoordinateY() const;
	
	void setCoordinateX(int coordinateX);
	void setCoordinateY(int coordinateY);

	const int generateId()const;
	friend std::ostream& operator<<(std::ostream& os, const Stop& stop);
	int calculateDistance(Stop& stop) const;

private:
	static int counterId;
	long id;
	int coordinateX;
	int coordinateY;
};