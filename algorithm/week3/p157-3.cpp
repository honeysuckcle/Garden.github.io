#include <iostream>
using namespace std;

typedef struct Position
{
	int x;
	int y;
}Positions; //表示坐标位置 

enum DIRECTION { N, NE, E, ES, S, WS, W, WN };
const Positions MOVE[8] = { {-1,0}, // N
						  {-1,1}, // NE
						  {0,1},  // E
						  {1,1},  // ES
						  {1,0},  // S
						  {1,-1}, // WS
						  {0,-1}, // W
						  {-1,-1} }; // WN
const int MAZE[8][8] = { 1,1,1,1,1,1,1,1,
						1,0,0,0,0,0,1,1,
						1,1,0,1,0,1,1,1,
						1,1,0,1,1,1,1,1,
						1,1,0,0,0,0,0,1,
						1,1,0,1,1,1,1,1,
						1,1,0,0,0,0,0,1,
						1,1,1,1,1,1,1,1 };
int mark[8][8] = { 0 };

int FindPxth(Position f_now, Position f_exit)  //f_now(x,y,d) 是（当前）尝试的位置和方向
{
	int g, h;  //(g,h) 是下一个要尝试的位置
	if (f_now.x == f_exit.x && f_now.y == f_exit.y) return 1;  //已经到达出口，返回1（真）

	for (int dir = 0; dir < 8; ++dir)  //对8个方向进行尝试
	{
		g = f_now.x + MOVE[dir].x;
		h = f_now.y + MOVE[dir].y;
		if (MAZE[g][h] == 0 && mark[g][h] == 0) //如果这个i方向可以过去
		{
			mark[g][h] = 1;   //走到那里 并标记那里已经来过了.
			Position next;
			next.x = g;
			next.y = h;
			if (FindPxth(next, f_exit))  //从这里递归查找
			{
				cout << "(" << g << "," << h << "," << dir << ")" << endl;  //回溯的时候逆向输出坐标和方向
				return 1;
			}
			//如果在这个地方递归没找到 从if（递归式）出来后, 走到这一行, 相当于又回到了f_now 这个位置,但尝试下一个方向(++dir)
			//起到了和栈相同的作用
		}
	}
	if (f_now.x == 1 && f_now.y == 1)  //如果从（1,1）开始递归尝试（深入~）。 遇到不通的路，一步一步跳出递归（参考第65行） 
		//最后跳出了 （1,1）的所有方向的递归尝试。 说明没有路径
		cout << "no pxth in maze!" << endl;
	return 0;
}
int main()
{
	cout << "The mxze is:" << endl;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
			cout << MAZE[i][j] << " ";
		cout << endl;
	}
	cout << "从开始到出口的逆向路径为：（x,y,方向）（方向从上一个点指向当前点）（dir = 0~7 = N~EN~E~...）\n";
	Position entrance = { 1,1 };  //定义入口
	Position exit = { 6,6 };  //定义出口
	FindPxth(entrance, exit);
	getchar();
	return 0;
}
