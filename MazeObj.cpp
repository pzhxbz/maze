#include "stdafx.h"
#include "MazeObj.h"


MazeObj::MazeObj()
{
	player.setRadius(10);
	player.setFillColor(sf::Color::Red);
	sf::Vector2f size(20, 20);
	wall.setSize(size);
	wall.setFillColor(sf::Color::Green);
	road.setSize(size);
	road.setFillColor(sf::Color::Black);
}


MazeObj::~MazeObj()
{
}

sf::Shape * MazeObj::get_shape(int shape)
{
	switch (shape)
	{
	case PLAYER:
		return &player;
	case WALL:
		return &wall;
	case ROAD:
		return &road;
	}
	return NULL;
}
