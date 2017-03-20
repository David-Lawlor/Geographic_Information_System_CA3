#include "TreeNode.h"


TreeNode::TreeNode(City cityIn) : city(cityIn), leftptr(nullptr), rightptr(nullptr)
{
}

TreeNode::~TreeNode()
{
}

bool TreeNode::isLeaf() const
{
	return (leftptr == nullptr && rightptr == nullptr);
}
