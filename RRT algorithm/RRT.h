#ifndef RRT_H
#define RRT_H

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

#endif