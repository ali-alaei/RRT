#ifndef OBSTACLES_H
#define OBSTACLES_H

class Obstacles
{

public:

	Obstacles(int ,int ,int);
	~Obstacles();
	int getX();
	int getY();
	int getRadius();

private:
	
	int x;
	int radius;
	int y;
};
#endif

