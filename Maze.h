#pragma once
#include <SFML\Graphics.hpp>
#include "MazeObj.h"
class Maze
{
public:
	Maze();
	Maze(int **a, int weight, int height);
	Maze(int a, int b);
	~Maze();
	void paint();
	void set_window(sf::RenderWindow* window);
	void init_maze();
private:
	int **maze;
	int weight;
	int heigth;
	sf::RenderWindow* window = NULL;
	void paint(int x, int y, sf::Shape* shape);
	void creat_maze(int x, int y);
};

