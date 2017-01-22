#ifndef NODES_H
#define NODES_H

class Nodes
{

public:

	Nodes(int, int, Nodes*);
	~Nodes();

	int getX();
	int getY();
	Nodes* getFatherNode();
	void setFatherNode(Nodes*);
	void setX(int);
	void setY(int);
	bool getIsReached();
	void setIsReached(bool);
private:
	
	bool isReached;
	Nodes* fatherNode;
	int x;
	int y;
	int distanceToRandNode;
};
#endif

