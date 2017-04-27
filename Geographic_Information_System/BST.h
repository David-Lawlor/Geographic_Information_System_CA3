#pragma once
#include "TreeNode.h"

class BST
{


public:
	BST();
	~BST();

	void insert(City cityIn);

	bool searchByCity(std::string cityName);
	bool searchByCoordinates(std::pair<double, double> coordinatesIn);

	bool deleteByCityName(std::string cityName);
	bool deleteByCoordinates(std::pair<double, double> coordinatesIn);

	int height();

	void preOrderTraversal();
	void inOrderTraversal();
	void postOrderTraversal();

	void printWithinDistance(int kilometers, std::pair<double, double> coordinatesIn);

private:
	TreeNode* root;
	void insert(TreeNode* node, TreeNode* newCity);

	bool searchByCity(TreeNode* root, std::string cityName);
	bool searchByCoordinates(TreeNode* root, std::pair<double, double> coordinatesIn);

	TreeNode* deleteByCityName(TreeNode* root, std::string cityName);
	bool deleteByCoordinates(TreeNode* root, std::pair<double, double> coordinatesIn);

	int height(TreeNode* root);

	void preOrderTraversal(TreeNode* node);
	void inOrderTraversal(TreeNode* root);
	void postOrderTraversal(TreeNode* node);

	TreeNode* findMin(TreeNode* node);
	
	void printWithinDistance(TreeNode* node, int kilometers, std::pair<double, double> coordinatesIn);
};

