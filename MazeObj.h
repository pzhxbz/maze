#pragma once
#include "stdafx.h"
#include <SFML\Graphics.hpp>
#define PLAYER 2
#define WALL 1
#define ROAD 0
class MazeObj
{
public:
	MazeObj();
	~MazeObj();
	sf::Shape *get_shape(int shape);
private:
	sf::CircleShape player;
	sf::RectangleShape wall;
	sf::RectangleShape road;

};

