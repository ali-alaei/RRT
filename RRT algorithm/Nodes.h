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
	float getDistanceToRandNode();
	void setDistanceToRandNode(float);
private:
	int x;
	int y;
	float distanceToRandNode;
};
#endif

