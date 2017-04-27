#include "BST.h"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <cmath> 

const double PI = 3.14;
const double earthRadiusKm = 6371.0;

/***************************************************************************************
*    Title: Haversine formula
*    Author: asdf, MrTJ
*    Date:  Apr 18 '12, edited 	Apr 19 '17
*    Code version: 2nd
*    Availability: http://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a
*	 USED
***************************************************************************************/
// This function converts decimal degrees to radians
double deg2rad(double deg) {
	return (deg * PI / 180);
}

/**
* Returns the distance between two points on the Earth.
* Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
* @param lat1d Latitude of the first point in degrees
* @param lon1d Longitude of the first point in degrees
* @param lat2d Latitude of the second point in degrees
* @param lon2d Longitude of the second point in degrees
* @return The distance between the two points in kilometers
*/
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/***************************************************************************************/



/**
public constructor which sets the root node to null
*/
BST::BST() : root(nullptr){}


/**
public destructor deletes the pointed to data when a the tree is deleted
*/
BST::~BST()
{
	delete root->leftptr;
	delete root->rightptr;
}


/**
public method to insert a new TreeNode with the city data

if the tree is empty make the new node the root otherwise call the 
private insert function with the root node and cityIn object passed in

@param cityIn - the city object to add to the new TreeNode
*/
void BST::insert(City cityIn)
{
	if (searchByCoordinates(cityIn.coordinates))
	{
		std::cout << "A city with those coordinates already exists in the tree" << std::endl;
	}
	else
	{
		TreeNode* newNode = new TreeNode(cityIn);
		if (root == nullptr) {
			root = newNode;
		}
		else {
			insert(newNode, root);
		}
	}
}

/**
private method to insert a new TreeNode with the city data

city name is compared by name and inserted into the correct location.
This method is called recursively passing the left or the right pointer of the 
node in based on the comparison result

@param node - the current node location in the tree
@param newNode - the new TreeNode to insert
*/
void BST::insert(TreeNode* newNode, TreeNode* node) 
{
	if (newNode->city < node->city) {
		if (node->leftptr == nullptr) {
			node->leftptr = newNode;
		}
		else {
			insert(newNode, node->leftptr);
		}
	}
	else if (newNode->city > node->city) {
		if (node->rightptr == nullptr) {
			node->rightptr = newNode;
		}
		else {
			insert(newNode, node->rightptr);
		}
	}
}



/**
public method to delete a city based on the city name

@param cityName - name of the city to delete
@return a boolean of whether the node was deleted or not
*/
bool BST::deleteByCityName(std::string cityName)
{
	return deleteByCityName(root, cityName) != nullptr;
}

/**
private method to delete a city based on the city coordinates

@param node - the root node of the tree
@param cityName - name of the city to delete
@return the pointer to the TreeNode being deleted
*/
TreeNode* BST::deleteByCityName(TreeNode* node, std::string cityName)
{
	if (node != nullptr)
	{
		if (node->city.cityName.compare(cityName) > 0)
		{
			node->leftptr = deleteByCityName(node->leftptr, cityName);
		}
		else if (node->city.cityName.compare(cityName) < 0)
		{
			node->rightptr = deleteByCityName(node->rightptr, cityName);
		}
		else
		{
			if (node->isLeaf())
			{
				delete node;
				node = nullptr;
			}
			else if (node->leftptr == nullptr)
			{
				TreeNode* temp = node;
				node = node->rightptr;
				delete temp;

			}
			else if (root->rightptr == nullptr)
			{
				TreeNode* temp = node;
				node = node->leftptr;
				delete temp;
			}
			else
			{
				TreeNode* temp = findMin(node->rightptr);
				node->city = temp->city;
				node->rightptr = deleteByCityName(node->rightptr, temp->city.cityName);
			}
		}
	}
	return node;
}



/**
public method to delete a city based on the city coordinates

@param coordinatesIn - coordinates of the city to delete
@return a boolean of whether the node was deleted or not
*/
bool BST::deleteByCoordinates(std::pair<double, double> coordinatesIn)
{
	return deleteByCoordinates(root, coordinatesIn);
}

/**
private method to delete a city based on the city coordinates

@param node - the root node of the tree
@param coordinatesIn - coordinates of the city to delete
@return a boolean of whether the node was deleted or not
*/
bool BST::deleteByCoordinates(TreeNode* node, std::pair<double, double> coordinatesIn)
{
	if (node != nullptr)
	{
		if (node->city.coordinates.first == coordinatesIn.first && node->city.coordinates.second == coordinatesIn.second)
		{
			return deleteByCityName(root, node->city.cityName) != nullptr;
		}
		return deleteByCoordinates(node->leftptr, coordinatesIn) || deleteByCoordinates(node->rightptr, coordinatesIn);
	}
	return false;
}
		


/**
public method to search the BST based on the city name

@param cityName - coordinates of the city to delete
@return boolean based on whether it was found or not
*/
bool BST::searchByCity(std::string cityName)
{
	return searchByCity(root, cityName);
}

/**
private method to find a node in the tree base on the coordinates

@param node - the root node of the tree
@param cityName - a string with the name of the city to search to search
@return boolean - whether the node was found or not
*/
bool BST::searchByCity(TreeNode* node, std::string cityName)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (node->city.cityName.compare(cityName) == 0)
	{
		return true;
	}
	else if (node->city.cityName.compare(cityName) > 0)
	{
		return searchByCity(node->leftptr, cityName);
	}
	else// if (node->city.city > cityName)
	{
		return searchByCity(node->rightptr, cityName);
	}
}



/**
public method to search the BST based on the city name

@param coordinatesIn -  a std::pair<double, double> containing the set of coordinates to search
@return boolean based on whether it was found or not
*/
bool BST::searchByCoordinates(std::pair<double, double> coordinatesIn)
{
	return searchByCoordinates(root, coordinatesIn);
}

/**
private method to find a node in the tree base on the coordinates

@param node - the root node of the tree
@param coordinatesIn - a std::pair<double, double> containing the set of coordinates to search
@return boolean - whether the node was found or not
*/
bool BST::searchByCoordinates(TreeNode* node, std::pair<double, double> coordinatesIn)
{
	if (node != nullptr)
	{
		if (node->city.coordinates.first == coordinatesIn.first && node->city.coordinates.second == coordinatesIn.second)
		{
			return true;
		}
		return (searchByCoordinates(node->leftptr, coordinatesIn) || searchByCoordinates(node->rightptr, coordinatesIn));
	}
	return false;
}



/**
public method to find the height of the tree

returns -1 for empty and 0 for height of 1 and 1 for height of 2 etc..

@return an integer with the height of the tree
*/
int BST::height() 
{
	return height(root);
}

/**
private method to find the height of the tree

returns -1 for empty and 0 for height of 1 and 1 for height of 2 etc..

@param node - the root node of the tree
@return an integer with the height of the tree
*/
int BST::height(TreeNode* node) 
{
	if (node == nullptr)
	{
		return -1;
	}
	return std::max(height(node->leftptr), height(node->rightptr)) + 1;

}



/**
public method preorder traversal

prints the tree data in a preorder
*/
void BST::preOrderTraversal()
{
	preOrderTraversal(root);
}

/**
private method preOrder traversal

@param node - TreeNode* root node of the tree
*/
void BST::preOrderTraversal(TreeNode* node)
{
	if (node != nullptr)
	{
		std::cout << node->city << std::endl;
		preOrderTraversal(node->leftptr);
		preOrderTraversal(node->rightptr);
		
	}
}



/**
public method inOrder traversal

prints the tree data in a inOrder
*/
void BST::inOrderTraversal() 
{
	inOrderTraversal(root);
}

/**
private method inOrder traversal

@param node - TreeNode* root node of the tree
*/
void BST::inOrderTraversal(TreeNode* node) 
{
	if (node != nullptr)
	{
		inOrderTraversal(node->leftptr);
		std::cout << node->city << std::endl;
		inOrderTraversal(node->rightptr);
	}
}



/**
public method postOrder traversal

prints the tree data in a postOrder
*/
void BST::postOrderTraversal()
{
	postOrderTraversal(root);
}

/**
private method postOrder traversal

@param node - TreeNode* root node of the tree
*/
void BST::postOrderTraversal(TreeNode* node)
{
	if (node != nullptr)
	{
		postOrderTraversal(node->leftptr);
		postOrderTraversal(node->rightptr);
		std::cout << node->city << std::endl;
	}
}



/**
private method findMin to find the minimum value node in the tree

@param node - TreeNode* root node of the tree
*/
TreeNode* BST::findMin(TreeNode* node)
{
	while (node->leftptr != nullptr)
	{
		node = node->leftptr;
	}
	return node;
}




void BST::printWithinDistance(int kilometers, std::pair<double, double> coordinatesIn)
{
	printWithinDistance(root, kilometers, coordinatesIn);
}

void BST::printWithinDistance(TreeNode* node, int kilometers, std::pair<double, double> coordinatesIn)
{
	if (node != nullptr)
	{
		printWithinDistance(node->leftptr, kilometers, coordinatesIn);
		double distance = distanceEarth(node->city.coordinates.first, node->city.coordinates.second, coordinatesIn.first, coordinatesIn.second);
		if (distance < kilometers)
		{
			std::cout << "The distance between the two points are " << distance << std::endl;
			std::cout << "The City details are " << std::endl;
			std::cout << node->city << "\n" << std::endl;
		}
		printWithinDistance(node->rightptr, kilometers, coordinatesIn);
	}
}



