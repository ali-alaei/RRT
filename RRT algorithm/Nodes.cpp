#include"Nodes.h"

Nodes::Nodes(int x, int y, Nodes* fatherNode)
{
	this->fatherNode = fatherNode;
	this-> x = x;
	this-> y = y;
	this->isReached = false;
}

Nodes::~Nodes()
{

}

bool Nodes::getIsReached()
{
	return isReached;
}

int Nodes::getX()
{
	return this->x;
}

int Nodes::getY()
{
	return this->y;
}

Nodes* Nodes::getFatherNode()
{
	return fatherNode;
}

void Nodes::setIsReached(bool isReached)
{
	this->isReached = isReached;

}


void Nodes::setFatherNode(Nodes* fatherNode)
{
	this->fatherNode = fatherNode;
}

void Nodes::setX(int x)
{
	this->x = x; 
}

void Nodes::setY(int y)
{
	this->y = y;
}

