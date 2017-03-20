#pragma once
#include <string>

class City
{
public:
	City(std::string cityIn, std::pair <double, double> coordinatesIn, int populationIn,
		double avgYearlyTemperatureIn);
	~City();

private:
	std::string city;
	std::pair <double, double> coordinates;
	int population;
	double avgYearlyTemperature;
};

