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

void RRT::fillObstacles()
{
	///build some obstacles randomize 
}

void RRT::fillDestAndStart()
{

}

void RRT::Navigate()
{
	Navigator navigate(this->start, this->dest);
	//fillObstacles();

	while (true)
	{
		navigate.getRandomState();
		//std::cout << "F";
		navigate.getNearestNode();
	//	std::cout << "H";

		//if (navigate.isValidExpansion())
		//{
			//std::cout << "E";
			navigate.addNode();
			navigate.goTowardsNode(robotPower);
			
			//std::cout << "W";
			//navigate.checkValues();

			if (navigate.isGoalReached())
			{
				navigate.setDestFather();
				//std::cout << "JOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOON";
				navigate.reverse();
				break;
			}
		//}
		

	}

}
