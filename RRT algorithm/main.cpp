

#include "RRT.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
int main()
{

	srand(time(0));
	std::vector <Nodes*>T;
	
	RRT object(new Nodes(0, 0, nullptr), new Nodes(45,79, nullptr), 1);
	object.Navigate(T);
	
	system("PAUSE");
	return 0;
}