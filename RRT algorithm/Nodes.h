#ifndef NODES_H
#define NODES_H

class Nodes
{

public:

	Nodes(int, int, Nodes*);
	~Nodes();

	//setter and getter
	int getX();
	int getY();
	Nodes* getFatherNode();
	void setFatherNode(Nodes*);
	void setX(int);
	void setY(int);
	bool getIsReached();
	void setIsReached(bool);
	//void makeNode();
	//float getDistanceToRandNode();
	//void setDistanceToRandNode(float);
private:
	
	bool isReached;
	Nodes* fatherNode;
	int x;
	int y;
	int distanceToRandNode;
};
#endif

