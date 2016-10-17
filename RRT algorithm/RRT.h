#ifndef RRT_H
#define RRT_H
#include <iostream>
#include "Navigator.h"

class RRT
{
public:
	RRT(Nodes*, Nodes*, int);
	~RRT();

	void fillObstacles();
	void fillDestAndStart();
	void Navigate();
	

private:
	Nodes* start;
	Nodes* dest;
	int robotPower;
//Navigator navigate(Nodes* , Nodes*);

};

#endif