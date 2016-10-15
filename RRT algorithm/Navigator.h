#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <cmath>
#include "Nodes.h"
#include "Obstacles.h"
#include <vector>

#define baseSize 100

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
	Nodes getNearestNode();
	bool isValidExpansion();
	void goTowardsNode(float);
	void addNode(Nodes);

private:
	void nodesDistanceToRandNode();

};
#endif
