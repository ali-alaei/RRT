#ifndef NODES_H
#define NODES_H

class Nodes
{
public:
	Nodes();
	~Nodes();
	void makeNodes();
	int getX();
	int getY();
	void setX(float);
	void setY(float);
	float getDistanceToRandNode();
	void setDistanceToRandNode(float);
private:
	float x;
	float y;
	float distanceToRandNode;
};
#endif

