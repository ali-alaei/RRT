

#include "RRT.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(0));
	RRT object(new Nodes(0, 0, nullptr), new Nodes(73,23 , nullptr), 1);
	object.Navigate();
	system("PAUSE");
	return 0;
}