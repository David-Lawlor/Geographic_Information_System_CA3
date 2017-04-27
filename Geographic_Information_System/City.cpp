#include "City.h"
#include <iostream>

City::City(std::string cityIn, std::pair<double, double> coordinatesIn, int populationIn, double avgYearlyTemperatureIn)
{
	cityName = cityIn;
	coordinates = coordinatesIn;
	population = populationIn;
	avgYearlyTemperature = avgYearlyTemperatureIn;
}

City::~City()
{
}

bool City::operator<(City cityIn) const
{
	return cityName.compare(cityIn.cityName) < 0;
}

bool City::operator>(City cityIn) const
{
	return cityName.compare(cityIn.cityName) > 0;
}


std::ostream& operator<<(std::ostream& os, const City& cityIn)
{
	os << "City: " + cityIn.cityName << std::endl;
	os << "Coordinates: " << cityIn.coordinates.first << "  " << cityIn.coordinates.second << std::endl;
	os << "Population: " << cityIn.population << std::endl;
	os << "Average Yearly Temperature: " << cityIn.avgYearlyTemperature << std::endl;
	return os;
}
