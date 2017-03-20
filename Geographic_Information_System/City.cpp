#include "City.h"

City::City(std::string cityIn, std::pair<double, double> coordinatesIn, int populationIn, double avgYearlyTemperatureIn)
{
	city = cityIn;
	coordinates = coordinatesIn;
	population = populationIn;
	avgYearlyTemperature = avgYearlyTemperatureIn;
}

City::~City()
{
}
