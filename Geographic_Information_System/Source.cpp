#include <string>
#include <iostream>
#include "BST.h"
#include <boost/timer/timer.hpp>
#include <boost/chrono.hpp>

int main()
{
	// create the tree
	BST tree = BST();

	// print height of empty tree
	std::cout << "The height of the empty tree is " << tree.height() << std::endl;

	// test data cities for the tree
	tree.insert(City("Dublin", std::make_pair(53.3498, 6.2603), 530000, 12));

	// print height of a single node tree
	std::cout << "The height of single node tree is " << tree.height() << std::endl;

	//Start Time Coordinates
	boost::timer::cpu_timer coordinateTimer;

	tree.insert(City("London", std::make_pair(51.5074, 0.1278), 8700000, 13));
	tree.insert(City("Paris", std::make_pair(48.8566, 2.3522), 2200000, 16));
	tree.insert(City("Budapest", std::make_pair(47.4979, 19.0402), 1800000, 19));
	tree.insert(City("Copenhagen", std::make_pair(55.6761, 12.5683), 600000, 16));
	tree.insert(City("Vienna", std::make_pair(48.2082, 16.3738), 1900000, 21));
	tree.insert(City("Stockholm", std::make_pair(59.3293, 18.0686), 940000, 8));
	tree.insert(City("Milan", std::make_pair(45.4654, 9.1859), 1345000, 15));
	tree.insert(City("Oslo", std::make_pair(59.9139, 10.7522), 660000, 10));
	tree.insert(City("Istanbul", std::make_pair(41.0082, 28.9784), 15000000, 26));

	// duplicate coordinates to test for no duplicate coordinates in tree
	tree.insert(City("Dublin", std::make_pair(53.3498, 6.2603), 530000, 12));

	//Output timer
	boost::timer::cpu_times coorElapsed = coordinateTimer.elapsed();
	std::cout << std::endl << "COOR CPU TIME: " << (coorElapsed.user + coorElapsed.system) / 1e9 << " seconds"
		<< " WALLCLOCK TIME: " << coorElapsed.wall / 1e9 << " seconds"
		<< std::endl;

	// print out the cities in alphabetical order
	tree.inOrderTraversal();

	// check the search by city name method (should be true)
	std::cout << "Is Istanbul in the tree (city name search) " << tree.searchByCity("Istanbul") << std::endl;

	// is non existing city in the tree
	std::cout << "Is fake city in the tree (city name search) " << tree.searchByCity("nbul") << std::endl;


	// check the search by coordinates method (should be true
	std::cout << "Is Istanbul in the tree (city coordinates search) " << tree.searchByCoordinates(std::make_pair(41.0082, 28.9784)) << std::endl;

	// is non existing city in the tree
	std::cout << "Is fake city in the tree (city coordinates search) " << tree.searchByCoordinates(std::make_pair(12.345, 34.567)) << std::endl;

	// print out the height of the tree
	std::cout << "The height of the tree is " << tree.height() << std::endl;

	// delete a city by name
	std::cout << "Deleting Oslo... (by city name)\n"  << std::endl;
	std::cout << tree.deleteByCityName("Oslo") << std::endl;

	// delete a city by name
	std::cout << "Deleting Dublin ... (by city name)\n" << std::endl;
	std::cout << tree.deleteByCityName("Dublin") << std::endl;
	
	// print out the cities in alphabetical order
	tree.inOrderTraversal();

	// delete a city by name
	std::cout << "Deleting Copenhagen ... (by city coordinates)\n" << std::endl;
	std::cout << tree.deleteByCoordinates(std::make_pair(55.6761, 12.5683)) << std::endl;

	// delete a city by name
	std::cout << "Deleting fake ... (by city coordinates)\n" << std::endl;
	std::cout << tree.deleteByCoordinates(std::make_pair(59.39, 1.72)) << std::endl;

	// print out the cities in alphabetical order
	tree.inOrderTraversal();

	tree.printWithinDistance(1000, std::make_pair(53.3498, 6.2603));

	system("pause");

	return 0;
}
