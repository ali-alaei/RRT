#ifndef RRT_H
#define RRT_H
#include <iostream>
#include "Navigator.h"

class RRT
{
public:
	RRT(Nodes*, Nodes*, int);
	~RRT();

	void fillDestAndStart();
	void Navigate(std::vector<Nodes*>&);
	

private:
	Nodes* start;
	Nodes* dest;
	int robotPower;
//Navigator navigate(Nodes* , Nodes*);

};

#endif