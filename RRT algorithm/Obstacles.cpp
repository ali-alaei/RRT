#include"Obstacles.h"

Obstacles::Obstacles(int xPos,int yPos,int radius)
{
	this->x = xPos;
	this->y = yPos;
	this->radius = radius;
}

Obstacles::~Obstacles()
{

}

int Obstacles::getX()
{
	return this->x;
}

int Obstacles::getY()
{
	return this->y;
}

int Obstacles::getRadius()
{
	return this->radius;
}
