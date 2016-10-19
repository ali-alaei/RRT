#include "RRT.h"


RRT::RRT(Nodes* start, Nodes* dest, int power)
{
	this->start = start;
	this->dest = dest;
	this->robotPower = power;
}


RRT::~RRT()
{
	//delete[] start;
//	delete[] dest;

}

void RRT::fillDestAndStart()
{

}

void RRT::Navigate(std::vector<Nodes*>&pathList)
{
	pathList.clear();
	Navigator navigate(this->start, this->dest);
	//fillObstacles();
	navigate.buildObstacles(1);

	while (true)
	{
		navigate.getRandomState();
		//std::cout << "F";
		navigate.getNearestNode();
	//	std::cout << "H";
		if (navigate.isValidExpansion())
		{
		//	std::cout << "\n\nCHECK\n\n";
			navigate.addNode();
			navigate.goTowardsNode(robotPower);
			
			//navigate.checkValues();

			if (navigate.isGoalReached())
			{
				navigate.setDestFather();
				navigate.reverse(pathList);
				break;
			}
		}
	}

}
