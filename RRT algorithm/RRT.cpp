#include "RRT.h"


RRT::RRT(Nodes* start, Nodes* dest, int power)
{
	this->start = start;
	this->dest = dest;
	this->robotPower = power;
}


RRT::~RRT()
{

}

void RRT::fillDestAndStart()
{

}

void RRT::Navigate(std::vector<Nodes*>&pathList, std::vector<Nodes*>&nodes, std::vector<Obstacles*>&obstacles)
{
	pathList.clear();
	nodes.clear();
	obstacles.clear();

	Navigator navigate(this->start, this->dest);

	navigate.buildObstacles(8,obstacles);

	while (true)
	{
		navigate.getRandomState();

		navigate.getNearestNode();

		navigate.addNode(nodes);
		if (navigate.goTowardsNode(robotPower))
		{
			if (navigate.isGoalReached())
			{
				navigate.setDestFather();
				navigate.reverse(pathList);
				break;
			}
		}
	}

}
