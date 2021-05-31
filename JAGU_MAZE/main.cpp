#include <Windows.h>
#include <iostream>

using namespace std;

#define MAZESIZE_X 12
#define MAZESIZE_Y 22
#define EXIT_X 11
#define EXIT_Y 16

typedef struct Position
{
	int x;
	int y;
	int d;
} _Pos;

typedef struct Mtable
{
	int x;
	int y;
} _Mtable;

int Maze[MAZESIZE_X][MAZESIZE_Y] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

_Mtable Move[4] =
{
	{ 0, 1 },
	{ 1, 0 },
	{ 0, -1 },
	{ -1, 0 },
};

int Mark[MAZESIZE_X][MAZESIZE_Y];
int top;
_Pos Trace[(MAZESIZE_X - 1) * (MAZESIZE_Y - 2)];

void ShowMaze(_Pos P);
void Push(_Pos P);
void Pop(_Pos* P);

int main()
{
	int isFound = FALSE;
	int i, dir;

	_Pos Now = { 1, 1, 0 };
	_Pos Next;

	Push(Now);
	while (!isFound && top > 0)
	{
		Pop(&Now);
		dir = Now.d;
		while (dir < 4)
		{
			Next.x = Now.x + Move[dir].x;
			Next.y = Now.y + Move[dir].y;

			if (Next.x == EXIT_X && Next.y == EXIT_Y)
			{
				Next.d = dir;
				Push(Next);
				isFound = TRUE;
				break;
			}
			else if ((Maze[Next.x][Next.y] == 0) && (Mark[Next.x][Next.y] == 0))
			{
				Now.d = ++dir;
				Push(Now);

				Now.x = Next.x;
				Now.y = Next.y;

				dir = 0;

				Mark[Next.x][Next.y] = 1;
			}
			else dir++;

			ShowMaze(Now);
		}
	}

	if (isFound == TRUE)
	{
		for (i = 0; i < top; i++)
		{
			ShowMaze(Trace[i]);
		}
	}
	else
	{
		cout << "Not Found" << endl;
	}

	system("pause");
	return 0;
}

void ShowMaze(_Pos P)
{
	int i, j;

	Sleep(50);
	system("cls");

	cout << "출구는 (11, 16)" << endl;
	cout << "현재 좌표는 " << P.x << " " << P.y << " " << P.d << endl;

	for (i = 0; i < MAZESIZE_X; i++)
	{

		for (j = 0; j < MAZESIZE_Y; j++)
		{
			if (Maze[i][j] == 1)
			{
				cout << "#";
			}
			else if (P.x == i && P.y == j)
			{
				cout << "&";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

void Push(_Pos P)
{
	Trace[top].x = P.x;
	Trace[top].y = P.y;
	Trace[top].d = P.d;
	top++;
}

void Pop(_Pos* P)
{
	top--;
	P->x = Trace[top].x;
	P->y = Trace[top].y;
	P->d = Trace[top].d;
}
