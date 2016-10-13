#include"Nodes.h"
Nodes::Nodes()
{
}

Nodes::~Nodes()
{
}
void Nodes::makeNodes()
{

}

int Nodes::getX()
{
	return this->x;
}

int Nodes::getY()
{
	return this->y;
}
float Nodes::getDistanceToRandNode()
{
	return this->distanceToRandNode;
}
void Nodes::setDistanceToRandNode(float distance)
{
	this->distanceToRandNode = distance;
}