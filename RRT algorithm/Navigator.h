#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "Nodes.h"
#include "Obstacles.h"
#include <vector>

class Navigator
{
	Nodes nearestNode;
	Nodes randomNode;
	Nodes newNode;
	std::vector	<Nodes> nodesList;
	std::vector	<Obstacles> obstaclesList;

public:
	Navigator();
	~Navigator();
	void getRandomState();
	void getNearestNode();
	bool isValidExpansion(Nodes,Nodes);
	void goTowardsNode();
private:


};
#endif
