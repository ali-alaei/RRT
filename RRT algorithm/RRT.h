#pragma once
#include "Navigator.h"

class RRT
{
public:
	RRT(Nodes,Nodes);
	~RRT();

	void fillObstacles();
	void fillDestAndStart();
	void Navigate();

private:


};

