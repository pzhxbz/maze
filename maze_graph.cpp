// maze_graph.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Maze.h"
#include "MazeObj.h"
#define WEIGTH 31
#define HEIGHT 31
int main()
{
	srand((unsigned)time(NULL));
	sf::RenderWindow window(sf::VideoMode(700, 700), "MAZE");
	Maze maze(WEIGTH, HEIGHT);
	maze.init_maze();
	maze.set_window(&window);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		maze.paint();
		window.display();
	}

	return 0;
}
