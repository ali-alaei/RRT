#include"Navigator.h"
using namespace std;
Navigator::Navigator(Nodes* start, Nodes* dest)
{
	this->randomNode = new Nodes(0, 0, nullptr);
	this->startNode = start;
	this->newNode = new Nodes(0, 0, nullptr);
	nodesList.push_back(startNode);
	this->destNode = dest;
}


Navigator::~Navigator()
{
}

bool Navigator::checkIfNewNodeIsNearDestination(Nodes* newnode, Nodes* dest, float radiusa)
{
	if (sqrt(pow((newnode->getX() - dest->getX()), 2) + pow((newnode->getY() - dest->getY()), 2)) <= radiusa)
	{
		return true;
	}
	else
		return false;
}

void Navigator::getRandomState()
{
	int xRand = rand() % baseSize;
	int yRand = rand() % baseSize;


	for (int i = 0; i < nodesList.size(); i++)
	{
		if (xRand == nodesList[i]->getX() && yRand == nodesList[i]->getY())
		{
			xRand = rand() %  baseSize;
			yRand = rand() %  baseSize;
			i = 0; 
		}
	}

	for (int j = 0; j < obstaclesList.size(); j++)
	{
		if (xRand <= obstaclesList[j]->getX() + obstaclesList[j]->getRadius() &&
			xRand >= obstaclesList[j]->getX() - obstaclesList[j]->getRadius())
		{
			if (yRand <= obstaclesList[j]->getY() + obstaclesList[j]-> getRadius() &&
				yRand >= obstaclesList[j]->getY() - obstaclesList[j]-> getRadius())
			{
				xRand = rand() %  baseSize;
				yRand = rand() %  baseSize;
				j = 0;
			}

		}
	}

	this->randomNode->setX(xRand);
	this->randomNode->setY(yRand);

}


void Navigator::getNearestNode()
{
	int shortestNode;
	int minDistance = sqrt(pow(nodesList[0]->getX() - randomNode->getX(), 2)
		+ pow(nodesList[0]->getY() - randomNode->getY(), 2));
	shortestNode = 0;

	for (int i = 1; i < nodesList.size(); i++)
	{
		int tempDistance = sqrt(pow(nodesList[i]->getX() - randomNode->getX(), 2) 
			+ pow(nodesList[i]->getY() - randomNode->getY(), 2));
		if (tempDistance < minDistance)
		{
			minDistance = tempDistance;
			shortestNode = i;
		}
	}

	this->nearestNode = nodesList[shortestNode];

}

bool Navigator::isValidExpansion2()
{
	for (int i = 0; i < obstaclesList.size(); i++)
	{
		if (randomNode->getX() > obstaclesList[i]->getX())
		{

		}

	}
}
bool Navigator::isValidExpansion()
{
	float fasele=0;
	float m = 0;
	float zaribeX;
	float c;


	if (randomNode->getX() - nearestNode->getX() == 0)
	{
		c = 0;
		m = 0;
		zaribeX = 0;
	}
	else
	{
		m = (randomNode->getY() - nearestNode->getY()) / (randomNode->getX() - nearestNode->getX());
		zaribeX = -1 * m;
		c = m * randomNode->getX() - randomNode->getY();
	}


	for (int i = 0; i < obstaclesList.size(); i++)
	{
		if (obstacleIsBetweenRandomAndNearestNodes(obstaclesList[i]))
		{
			cout << "  F  ";
			fasele = abs((zaribeX * obstaclesList[i]->getX()) + (obstaclesList[i]->getY()) + c) / sqrt(pow(zaribeX, 2) + 1);
		
			if (fasele <= obstaclesList[i]->getRadius())
			{
				return false;
			}
		}
	}
	return true;
}

bool Navigator::goTowardsNode(int maxEdgeLength)
{
		int distance;
		int d;

		distance = sqrt(pow(nearestNode->getX() - randomNode->getX(), 2) + pow(nearestNode->getY() - randomNode->getY(), 2));
		d = maxEdgeLength;

		if (distance == 0)
			distance = 1;
		for (int i = 0; i < obstaclesList.size(); i++)
		{
			if ((nearestNode->getX() + d * ((randomNode->getX() - nearestNode->getX()) / distance) < obstaclesList[i]->getX() + obstaclesList[i]->getRadius()) && ((nearestNode->getX() + d * ((randomNode->getX() - nearestNode->getX()) / distance)) >= obstaclesList[i]->getX() - obstaclesList[i]->getRadius()))
			{
				if ((nearestNode->getY() + d * ((randomNode->getY() - nearestNode->getY()) / distance) < obstaclesList[i]->getY() + obstaclesList[i]->getRadius()) && (nearestNode->getY() + d * ((randomNode->getY() - nearestNode->getY()) / distance) >= obstaclesList[i]->getY() - obstaclesList[i]->getRadius()))
				{
					return false;
				}
			}
		}
		newNode->setX(nearestNode->getX() + d * ((randomNode->getX() - nearestNode->getX()) / distance));

		newNode->setY(nearestNode->getY() + d * ((randomNode->getY() - nearestNode->getY()) / distance));

		newNode->setFatherNode(this->nearestNode);

		return true;
}


void Navigator::addNode(std::vector<Nodes*>&retrurnedNodeList)
{
	this->newNode = new Nodes(0, 0, nullptr);
	nodesList.push_back(newNode);
	retrurnedNodeList = this->nodesList;
}

bool Navigator::isGoalReached()
{

	if (checkIfNewNodeIsNearDestination(this->newNode, this->destNode, 1))
		return true;
	else
		return false;
}

void Navigator::reverse(std::vector<Nodes*>&retrurnedPathList)
{
	cout << "\nReverse\n";
	flagNode = destNode;
	pathList.push_back(destNode);

	while (flagNode->getFatherNode() != nullptr)
	{
		pathList.push_back(flagNode->getFatherNode());
		flagNode = flagNode->getFatherNode();
	}

	pathList.push_back(startNode);

	retrurnedPathList = pathList;
}

void Navigator::buildObstacles(int obstaclesNumber, std::vector<Obstacles*>&obstaclesReturnedList)
{
		this->obstaclesList.push_back(new Obstacles(22,11,3));
		this->obstaclesList.push_back(new Obstacles(25, 33, 3));
		this->obstaclesList.push_back(new Obstacles(50, 60, 3));
		this->obstaclesList.push_back(new Obstacles(50, 60, 3));
		this->obstaclesList.push_back(new Obstacles(10, 60, 3));
		this->obstaclesList.push_back(new Obstacles(30, 42, 3));
		this->obstaclesList.push_back(new Obstacles(40, 42, 3));
		this->obstaclesList.push_back(new Obstacles(50, 82, 3));
		this->obstaclesList.push_back(new Obstacles(20, 92, 3));
		this->obstaclesList.push_back(new Obstacles(80, 42, 3));
		this->obstaclesList.push_back(new Obstacles(30, 40, 1));
		this->obstaclesList.push_back(new Obstacles(4, 5, 3));

		obstaclesReturnedList = this->obstaclesList;

}

void Navigator::setDestFather()
{
	this->destNode->setFatherNode(newNode);
}

bool Navigator::obstacleIsBetweenRandomAndNearestNodes(Obstacles* T)
{
	if (T->getX() < nearestNode->getX() && T->getX() > nearestNode->getX())
		if (T->getY() < nearestNode->getY() && T->getY() > nearestNode->getY())
			return true;
	
	return false;
}


//start Node Father darad ke nabayad dashte bashe  ok
//dest node Fatheresh akharesh nabood mishe  ok
//int kardam hamaro
//peyda mikone   ok
//list node ha daghoon shode (chert o pert mide vali path okeye)
