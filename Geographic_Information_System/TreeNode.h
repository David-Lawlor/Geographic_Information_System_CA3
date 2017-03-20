#pragma once
#include "City.h"

class TreeNode
{
public:
	TreeNode(City cityIn);
	~TreeNode();
	bool isLeaf() const;
private: 
	City city;
	TreeNode* leftptr;
	TreeNode* rightptr;
};

