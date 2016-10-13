#include"Navigator.h"

void Navigator::getRandomState()
{

}
void Navigator::getNearestNode()
{


}
bool Navigator::isValidExpansion(Nodes Nearest,Nodes Random)
{
	this->nearestNode = Nearest;
	this->randomNode = Random;

	if (this->nearestNode.getX() - this->randomNode.getX() > 0 && this->nearestNode.getY() - this->randomNode.getY() > 0)
	{
		for (int i = this->nearestNode.getX(), j = this->nearestNode.getY(); i < this->randomNode.getX(), j < this->randomNode.getY();
			i += (this->randomNode.getX() / 100), j += (this->randomNode.getY() / 100))
		{
			for (int k = 0; k < obstaclesList.size(); k++)
			{
				if (obstaclesList[k].getX() + obstaclesList[k].getRadius() < i &&
					obstaclesList[k].getX() - obstaclesList[k].getRadius() > i)
				{
					if (obstaclesList[k].getY() + obstaclesList[k].getRadius() < j &&
						obstaclesList[k].getY() - obstaclesList[k].getRadius() > j)
					{
						return false;
					}
				}

			}
		}
	}
	
	else
	{
		for (int i = this->nearestNode.getX(), j = this->nearestNode.getY(); i < this->randomNode.getX(), j < this->randomNode.getY();
			i -= (this->randomNode.getY() / 100), j -= (this->randomNode.getY() / 100))
		{
			for (int k = 0; k < obstaclesList.size(); k++)
			{
				if (obstaclesList[k].getX() + obstaclesList[k].getRadius() < i &&
					obstaclesList[k].getX() - obstaclesList[k].getRadius() > i)
					{
						if (obstaclesList[k].getY() + obstaclesList[k].getRadius() < j &&
							obstaclesList[k].getY() - obstaclesList[k].getRadius() > j)
						{
							return false;
						}
					}

			}
		}

	}

	return true;
	
}

void Navigator::goTowardsNode()
{


}


Navigator::Navigator()
{
}

Navigator::~Navigator()
{
}