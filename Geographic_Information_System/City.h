#pragma once
#include <string>

class City
{
	friend std::ostream & operator<<(std::ostream& str, const City& cityIn);
	friend class TreeNode;
	friend class BST;

public:
	City(std::string cityIn, std::pair <double, double> coordinatesIn, int populationIn,
		double avgYearlyTemperatureIn);
	~City();
	bool operator<(City cityIn) const;
	bool operator>(City cityIn) const;

private:
	std::string cityName;
	std::pair <double, double> coordinates;
	int population;
	double avgYearlyTemperature;
};

