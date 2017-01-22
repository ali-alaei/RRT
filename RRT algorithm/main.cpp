

#include "RRT.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "Graphic.h"

int main()
{

	srand(time(0));
	std::vector <Nodes*>pathNodes;
	std::vector <Nodes*>nodes;
	std::vector <Obstacles*>obstacles; 
	RRT object(new Nodes(30, 33, nullptr), new Nodes(40,77, nullptr),1);
	object.Navigate(pathNodes,nodes,obstacles);
	Graphic mygraphic(pathNodes, nodes, obstacles);
	mygraphic.showNodes();
	system("PAUSE");
	return 0;
}