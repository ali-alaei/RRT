#ifndef OBSTACLES_H
#define OBSTACLES_H

class Obstacles
{

public:
	
	Obstacles();
	~Obstacles();
	void makeObstacles();
	float getX();
	float getY();
	float getRadius();

private:
	
	float x;
	float radius;
	float y;
};
#endif

