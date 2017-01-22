#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <cmath>
#include "Nodes.h"
#include "Obstacles.h"
#include <iostream>
#include <vector>

#define baseSize 100
#define radius 
class Navigator
{
	Nodes* nearestNode;
	Nodes* randomNode;
	Nodes* newNode;
	Nodes* startNode;
	Nodes* destNode;
	Nodes* flagNode;
	
	std::vector	<Nodes*> nodesList;
	std::vector	<Obstacles*> obstaclesList;
	std::vector <Nodes*> pathList;

public:
	Navigator(Nodes* start,Nodes* dest);
	~Navigator();
	bool checkIfNewNodeIsNearDestination(Nodes*,Nodes*,float);

	void setDestFather();
	void reverse(std::vector<Nodes*>&);
	bool obstacleIsBetweenRandomAndNearestNodes(Obstacles*);

	void getRandomState();
	void getNearestNode();
	void buildObstacles(int, std::vector<Obstacles*>&);
	bool isValidExpansion();
	bool isValidExpansion2();
	bool goTowardsNode(int);
	void addNode(std::vector<Nodes*>&);
	bool isGoalReached();

private:
	void nodesDistanceToRandNode();

};
#endif
