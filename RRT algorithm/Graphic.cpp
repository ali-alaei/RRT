#include"Graphic.h"

void Graphic::showNodes()
{	
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	
	sf::CircleShape pathNode(nodeRadius);
	pathNode.setFillColor(sf::Color::Red);
	
	sf::RectangleShape obstaclesNode(sf::Vector2f(20,20));
	obstaclesNode.setFillColor(sf::Color::Blue);
	
	sf::CircleShape allOfTheNodes(nodeRadius);
	allOfTheNodes.setFillColor(sf::Color::White);

	for (unsigned int i = 0; i < pathList.size(); i++)
	{
		pathNodesForShow.push_back(pathNode);
		pathNodesForShow[i].setPosition(pathList[i]->getX() * scale, pathList[i]->getY() * scale);
	}
	for (unsigned int j = 0; j < obstacles.size(); j++)
	{
		obstaclesForShow.push_back(obstaclesNode);
		obstaclesForShow[j].setPosition(obstacles[j]->getX() * scale, obstacles[j]->getY() * scale);
	}

	for (unsigned int k = 0; k < allNodes.size(); k++)
	{
		allNodesForShow.push_back(allOfTheNodes);
		allNodesForShow[k].setPosition(allNodes[k]->getX() * scale , allNodes[k]->getY() * scale);
	}

	for (unsigned int j = 0; j < allNodes.size(); j++)	
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
		

			for (unsigned int j = 0; j < allNodesForShow.size(); j++)
			{
				window.draw(allNodesForShow[j]);
			}
			for (unsigned int i = 0; i < pathNodesForShow.size(); i++)
			{
				window.draw(pathNodesForShow[i]);
			}

			for (unsigned int k = 0; k < obstaclesForShow.size(); k++)
			{
				window.draw(obstaclesForShow[k]);
			}

			window.display();
		}
}
Graphic::Graphic(std::vector<Nodes*>&pathNodes, std::vector<Nodes*>&allNodes, std::vector<Obstacles*>&obstacles)
{
	this->allNodes = allNodes;
	this->pathList = pathNodes;
	this->obstacles = obstacles;
}

Graphic::~Graphic()
{
}
