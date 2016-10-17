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
		if (xRand < obstaclesList[j].getX() + obstaclesList[j].getRadius() &&
			xRand > obstaclesList[j].getX() - obstaclesList[j].getRadius())
		{
			if (yRand < obstaclesList[j].getY() + obstaclesList[j].getRadius() &&
				yRand > obstaclesList[j].getY() - obstaclesList[j].getRadius())
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

/*
void Navigator::nodesDistanceToRandNode()
{
	for (int i = 0; i < nodesList.size(); i++)
	{
		nodesList[i]->setDistanceToRandNode(sqrt(pow(nodesList[i]->getX() - randomNode->getX(), 2) + pow(nodesList[i]->getY() - randomNode->getY(), 2)));
	}
}
*/

void Navigator::getNearestNode()
{
	int shortestNode;
	int minDistance = sqrt(pow(nodesList[0]->getX() - randomNode->getX(), 2) + pow(nodesList[0]->getY() - randomNode->getY(), 2));
	shortestNode = 0;

	for (int i = 1; i < nodesList.size(); i++)
	{
		int tempDistance = sqrt(pow(nodesList[i]->getX() - randomNode->getX(), 2) + pow(nodesList[i]->getY() - randomNode->getY(), 2));
		if (tempDistance < minDistance)
		{
			minDistance = tempDistance;
			shortestNode = i;
		}
	}

	this->nearestNode = nodesList[shortestNode];

}


bool Navigator::isValidExpansion()
{
	if (this->nearestNode->getX() - this->randomNode->getX() > 0 && this->nearestNode->getY() - this->randomNode->getY() > 0)
	{
		for (int i = this->nearestNode->getX(), j = this->nearestNode->getY(); i < this->randomNode->getX(), j < this->randomNode->getY();
			i += (this->randomNode->getX() / 100), j += (this->randomNode->getY() / 100))
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
		for (int i = this->nearestNode->getX(), j = this->nearestNode->getY(); i < this->randomNode->getX(), j < this->randomNode->getY();
			i -= (this->randomNode->getY() / 100), j -= (this->randomNode->getY() / 100))
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

void Navigator::goTowardsNode(int maxEdgeLength)
{
	int distance;
	int d;
	//cout << "\nUUUUUUU\n";
	distance = sqrt(pow(nearestNode->getX() - randomNode->getX(), 2) + pow(nearestNode->getY() - randomNode->getY(), 2));
	d = maxEdgeLength;
	//cout << "\nRRRRRRRRRRR\n";
	newNode->setX(nearestNode->getX() + d * ((randomNode->getX() - nearestNode->getX()) / distance));
	//cout << "\nDDDDDDD\n";
	newNode->setY(nearestNode->getY() + d * ((randomNode->getY() - nearestNode->getY()) / distance));
	//cout << "\nWWWWWW\n";
	newNode->setFatherNode(this->nearestNode);
	//cout << "\nSSSSSSSS\n";
}


void Navigator::addNode()
{
	this->newNode = new Nodes(0, 0, nullptr);
	nodesList.push_back(newNode);
}

bool Navigator::isGoalReached()
{

	if (checkIfNewNodeIsNearDestination(this->newNode, this->destNode, 1))
		return true;
	else
		return false;
	//if (this->newNode->getX() == this->destNode->getX() && this->newNode->getY() == this->destNode->getY())
	//{
	//	return true;
	//}
}

void Navigator::reverse()
{
	cout << "\nReverse\n";
	flagNode = destNode;
	pathList.push_back(destNode);

	while (flagNode->getFatherNode() != nullptr)
	{
	//	cout << "HHHHHHHHHHHHHHHHHHHHHHH";
		pathList.push_back(flagNode->getFatherNode());
		flagNode = flagNode->getFatherNode();
	}

	pathList.push_back(startNode);
	checkValues();

}

void Navigator::checkValues()
{
	std::cout << "nodelist size : " << nodesList.size()<< endl;
	
	for (int i = 1; i < nodesList.size(); i++)
		cout << "X : " << nodesList[i-1]->getX() << "    Y:    " << nodesList[i-1]->getY()
			<< "    XF : " << nodesList[i]->getFatherNode()->getX() <<"   YF :   "<< nodesList[i]->getFatherNode()->getY() << endl<<endl;// << "    Y:    " << nodesList[i]->getFatherNode() == nullptr << endl;
	

	std::cout << "obstacles size : " << obstaclesList.size() << endl;
	
	std::cout << "pathlist size : " << pathList.size() << endl;
	
	for (int i = 0; i < pathList.size(); i++)
	{
		cout << "X : " << pathList[i]->getX() << "    Y:    " << pathList[i]->getY() << endl;
	}

	std::cout << "random : " << (randomNode != nullptr)<<endl;
	 
	cout << "X: " << randomNode->getX() << "  Y:   " << randomNode->getY()<<endl;
	
	std::cout << "nearest : " << (nearestNode != nullptr) << endl;
	
	std::cout << "new  : " << (newNode != nullptr) << endl;
	
	cout << "X: " << newNode->getX() << "  Y:   " << newNode->getY() << endl;

	std::cout << "start : " << (startNode != nullptr) << endl;
	
	cout << "X: " << startNode->getX() << "  Y:   " << startNode->getY()<<endl;
	
	std::cout << "dest : " << (destNode != nullptr) << endl;
	
	cout << "X: " << destNode->getX() << "  Y:   " << destNode->getY()<<endl;
	
	std::cout << "flag : " << (flagNode != nullptr) << endl<<endl;
}

void Navigator::setDestFather()
{
	this->destNode->setFatherNode(newNode);
}


//start Node Father darad ke nabayad dashte bashe
//dest node Fatheresh akharesh nabood mishe
//int kardam hamaro
//peyda mikone
