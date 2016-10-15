#include"Navigator.h"


void Navigator::getRandomState()
{
	float xRand = rand() % 0 + baseSize;
	float yRand = rand() % 0 + baseSize;

	for (int i = 0; i < nodesList.size(); i++)
	{
		if (xRand == nodesList[i].getX() && yRand == nodesList[i].getY())
		{
			xRand = rand() % 0 + baseSize;
			yRand = rand() % 0 + baseSize;
			i = 0;
		}
	}
	for (int j = 0; j < obstaclesList.size(); j++)
	{
		if (xRand < obstaclesList[j].getX() + obstaclesList[j].getRadius() &&
			xRand > obstaclesList[j].getX() - obstaclesList[j].getRadius())
		{
			if (yRand < obstaclesList[j].getY() + obstaclesList[j].getRadius() &&
				yRand > obstaclesList[j].getY() - obstaclesList[j].getRadius())
			{
				xRand = rand() % 0 + baseSize;
				yRand = rand() % 0 + baseSize;
				j = 0;
			}

		}
	}

	this->randomNode.setX(xRand);
	this->randomNode.setY(yRand);

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


bool Navigator::isValidExpansion()
{
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

void Navigator::goTowardsNode(float maxEdgeLength)
{
	float distance;
	float d;
	
	distance = sqrt(pow(nearestNode.getX() - randomNode.getX(), 2) + pow(nearestNode.getY() - randomNode.getY(), 2));
	d = maxEdgeLength;
	
	newNode.setX(nearestNode.getX() + d * ((randomNode.getX() - nearestNode.getX()) / distance));
	newNode.setY(nearestNode.getY() + d * ((randomNode.getY() - nearestNode.getY()) / distance));
}

void Navigator::addNode(Nodes newNode)
{

}


Navigator::Navigator()
{
}

Navigator::~Navigator()
{
}