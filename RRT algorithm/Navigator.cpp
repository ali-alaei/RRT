#include"Navigator.h"

void Navigator::getRandomState()
{

}
void Navigator::nodesDistanceToRandNode()
{
	for (int i = 0; i < nodesList.size(); i++)
	{
		nodesList[i].setDistanceToRandNode(sqrt(pow(nodesList[i].getX() - randomNode.getX(), 2) + pow(nodesList[i].getY() - randomNode.getY(), 2)));
	}
}
Nodes Navigator::getNearestNode()
{
	float minDistance = sqrt(pow(nodesList[0].getX() - randomNode.getX(), 2) + pow(nodesList[0].getY() - randomNode.getY(), 2));
	for (int i = 1; i < nodesList.size(); i++)
	{
		float tempDistance = sqrt(pow(nodesList[i].getX() - randomNode.getX(), 2) + pow(nodesList[i].getY() - randomNode.getY(), 2));
		if (tempDistance < minDistance)
		{
			minDistance = tempDistance;
		}
		if (nodesList[i].getDistanceToRandNode() == minDistance)
		{
			return nodesList[i];
		}
	}
}
bool Navigator::isValidExpansion(Nodes Nearest,Nodes Random)
{
	this->nearestNode = Nearest;   //these 2 are having problem,they must be vice versa.
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