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
	void Navigate(std::vector<Nodes*>&, std::vector<Nodes*>&, std::vector<Obstacles*>&);
	

private:
	Nodes* start;
	Nodes* dest;
	int robotPower;

};

#endif