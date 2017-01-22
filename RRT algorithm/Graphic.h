#ifndef Graphic_H
#define Graphic_H
#include <SFML/Graphics.hpp>
#include"Nodes.h"
#include"Navigator.h"
#include<iostream>

#define nodeRadius 10
#define scale 10

class Graphic
{
public:
	Graphic(std::vector<Nodes*>&, std::vector<Nodes*>&, std::vector<Obstacles*>&);
	~Graphic();
	void showNodes();
	void showPath();

private:
	std::vector <sf::CircleShape> pathNodesForShow;
	std::vector <sf::CircleShape> allNodesForShow;
	std::vector <sf::RectangleShape> obstaclesForShow;

	std::vector <Nodes*> pathList;
	std::vector <Nodes*> allNodes;
	std::vector <Obstacles*> obstacles;

};
#endif Graphic_H
