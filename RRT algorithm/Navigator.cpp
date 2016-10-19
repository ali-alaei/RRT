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
				//cout << "QQQQQQQQ";
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

//in tabe kasif zade shode 
//bayad dorost she
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
			fasele = abs((zaribeX * obstaclesList[i]->getX()) + (obstaclesList[i]->getY()) + c) / sqrt(pow(zaribeX, 2) + 1);
			//momas ro ham barkhord gereftam
			if (fasele <= obstaclesList[i]->getRadius())
			{
			//	cout << "\n\nNA\n\n";

		//		cout << "\n \n \nFASELE :" << fasele << "\n \n \n";
				
		//		std::cout << "random : " << (randomNode != nullptr) << endl;

			//	cout << "X: " << randomNode->getX() << "  Y:   " << randomNode->getY() << endl;

			//	std::cout << "nearest : " << (nearestNode != nullptr) << endl;

			//	cout << "X: " << nearestNode->getX() << "  Y:   " << nearestNode->getY() << endl;

				return false;
			}
		}
	}
//	cout << "\n \n \nM :" << m << "\n \n \n";
	//cout << "\n \n \nC :" << c << "\n \n \n";
	//cout << "\n \n \nzaribeX :" << zaribeX << "\n \n \n";
	//cout << "\n \n \nFASELE :" << fasele << "\n \n \n";

	//cout <<"\n \n \nFASELE :"<< fasele<<"\n \n \n";

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
	if (distance == 0)
		distance = 1;
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

void Navigator::reverse(std::vector<Nodes*>&retrurnedPathList)
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

	retrurnedPathList = pathList;
}

void Navigator::buildObstacles(int obstaclesNumber)
{
		this->obstaclesList.push_back(new Obstacles(2,1,1));
		this->obstaclesList.push_back(new Obstacles(45, 23, 6));
		this->obstaclesList.push_back(new Obstacles(50, 50, 1));
		this->obstaclesList.push_back(new Obstacles(10, 12, 2));
		this->obstaclesList.push_back(new Obstacles(70, 32, 3));

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

	for (int i = 0; i < obstaclesList.size(); i++)
	{
		cout << "\n OX : " << obstaclesList[i]->getX() << "    OY:    " << obstaclesList[i]->getY() << endl;
	}

	
	std::cout << "random : " << (randomNode != nullptr)<<endl;
	 
	cout << "X: " << randomNode->getX() << "  Y:   " << randomNode->getY()<<endl;
	
	std::cout << "nearest : " << (nearestNode != nullptr) << endl;
	
	cout << "X: " << nearestNode->getX() << "  Y:   " << nearestNode->getY() << endl;

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

bool Navigator::obstacleIsBetweenRandomAndNearestNodes(Obstacles* T)
{
	if (T->getX() < randomNode->getX() && T->getX() > nearestNode->getX())
		if (T->getY() < randomNode->getY() && T->getY() > nearestNode->getY())
			return true;
	
	return false;
}


//start Node Father darad ke nabayad dashte bashe  ok
//dest node Fatheresh akharesh nabood mishe  ok
//int kardam hamaro
//peyda mikone   ok
//list node ha daghoon shode (chert o pert mide vali path okeye)
