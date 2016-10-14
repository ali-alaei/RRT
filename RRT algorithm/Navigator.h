#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include <cmath>
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
	Nodes getNearestNode();
	bool isValidExpansion(Nodes,Nodes);
	void goTowardsNode(float);
	void addNode(Nodes);

private:
	void nodesDistanceToRandNode();

};
#endif
