#include "stdafx.h"
#include "Maze.h"


Maze::Maze()
{
}


Maze::Maze(int ** a, int heigth, int weight)
{
	maze = a;
	this->heigth = heigth;
	this->weight = weight;
}

Maze::Maze(int a, int b)
{
	if (a % 2 == 0)
	{
		a++;
	}
	if (b % 2 == 0)
	{
		b++;
	}
	weight = a;
	heigth = b;
}

Maze::~Maze()
{
}

void Maze::paint()
{
	if (window == NULL)
	{
		return;
	}
	MazeObj obj;
	for (int i = 0; i < heigth + 2; i++)
	{
		for (int j = 0; j < weight + 2; j++)
		{
			paint(i, j, obj.get_shape(maze[i][j]));
		}
	}
}

void Maze::set_window(sf::RenderWindow* window)
{
	this->window = window;
}

void Maze::creat_maze(int x, int y)
{
	int rand_direct[4][2] = { 0 };
	int direct[4][2] = { 0,1,  1,0,  0,-1,  -1,0 };//四个方向
	int random[4] = { 0 };
	for (int i = 0; i < 4; i++)//生成4个不同的随机数
	{
		random[i] = rand() % 4;
		for (int j = 0; j < i; j++)
		{
			if (random[i] == random[j])
			{
				i--;
			}
		}
	}
	for (int i = 0; i < 4; i++)//将方向打乱
	{
		rand_direct[i][0] = direct[random[i]][0];
		rand_direct[i][1] = direct[random[i]][1];
	}
	maze[x][y] = ROAD;
	for (int i = 0; i < 4; i++)
	{
		if (maze[x + 2 * rand_direct[i][0]][y + 2 * rand_direct[i][1]] == WALL)
		{
			maze[x + rand_direct[i][0]][y + rand_direct[i][1]] = ROAD;
			creat_maze(x + 2 * rand_direct[i][0], y + 2 * rand_direct[i][1]);
		}
	}
}

void Maze::paint(int x, int y, sf::Shape * shape)
{
	shape->setPosition(x * 20, y * 20);
	window->draw(*shape);
}

void Maze::init_maze()
{
	maze = new int*[heigth + 2];
	for (int i = 0; i < heigth + 2; i++)
	{
		maze[i] = new int[weight + 2];
	}

	for (int i = 0; i <= heigth + 1; i++)
	{
		for (int j = 0; j <= weight + 1; j++)
		{
			if (i == 0 || i == heigth + 1 || j == 0 || j == weight + 1) //初始化迷宫
			{
				maze[i][j] = ROAD;
			}
			else
			{
				maze[i][j] = WALL;
			}
		}
	}
	creat_maze(2 * (rand() % (heigth / 2) + 1), 2 * (rand() % (weight / 2) + 1)); //从随机一个点开始生成迷宫，该点行列都为偶数
	for (int i = 0; i <= heigth + 1; i++) //边界处理
	{
		maze[i][0] = WALL;
		maze[i][weight + 1] = WALL;
	}
	for (int j = 0; j <= weight + 1; j++) //边界处理
	{
		maze[0][j] = WALL;
		maze[heigth + 1][j] = WALL;
	}
	maze[2][1] = PLAYER; //给定入口
	maze[heigth - 1][weight] = ROAD; //给定出口
}
