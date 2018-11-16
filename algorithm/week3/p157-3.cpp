#include <iostream>
using namespace std;

typedef struct Position
{
	int x;
	int y;
}Positions; //��ʾ����λ�� 

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

int FindPxth(Position f_now, Position f_exit)  //f_now(x,y,d) �ǣ���ǰ�����Ե�λ�úͷ���
{
	int g, h;  //(g,h) ����һ��Ҫ���Ե�λ��
	if (f_now.x == f_exit.x && f_now.y == f_exit.y) return 1;  //�Ѿ�������ڣ�����1���棩

	for (int dir = 0; dir < 8; ++dir)  //��8��������г���
	{
		g = f_now.x + MOVE[dir].x;
		h = f_now.y + MOVE[dir].y;
		if (MAZE[g][h] == 0 && mark[g][h] == 0) //������i������Թ�ȥ
		{
			mark[g][h] = 1;   //�ߵ����� ����������Ѿ�������.
			Position next;
			next.x = g;
			next.y = h;
			if (FindPxth(next, f_exit))  //������ݹ����
			{
				cout << "(" << g << "," << h << "," << dir << ")" << endl;  //���ݵ�ʱ�������������ͷ���
				return 1;
			}
			//���������ط��ݹ�û�ҵ� ��if���ݹ�ʽ��������, �ߵ���һ��, �൱���ֻص���f_now ���λ��,��������һ������(++dir)
			//���˺�ջ��ͬ������
		}
	}
	if (f_now.x == 1 && f_now.y == 1)  //����ӣ�1,1����ʼ�ݹ鳢�ԣ�����~���� ������ͨ��·��һ��һ�������ݹ飨�ο���65�У� 
		//��������� ��1,1�������з���ĵݹ鳢�ԡ� ˵��û��·��
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
	cout << "�ӿ�ʼ�����ڵ�����·��Ϊ����x,y,���򣩣��������һ����ָ��ǰ�㣩��dir = 0~7 = N~EN~E~...��\n";
	Position entrance = { 1,1 };  //�������
	Position exit = { 6,6 };  //�������
	FindPxth(entrance, exit);
	getchar();
	return 0;
}
