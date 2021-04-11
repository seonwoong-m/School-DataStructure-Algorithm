#include <iostream>
#include <stack>

using namespace std;

#define SIZE 10

typedef struct
{
	int stackArr[SIZE];
	int topIndex;
}_stack;

typedef _stack* pstack;

void Push(pstack ps, int n);

int Pop(pstack ps);

int main()
{
	int n = 0;
	_stack stackN;
	
	cin >> n;

	for (int i = 0; i < SIZE; i++)
	{
		Push(&stackN, (n % 10));
		n /= 10;
	}

	for (int i = 0; i < SIZE; i++)
	{
		Pop(&stackN);
	}

	return 0;
}

void Push(pstack ps, int n)
{
	if (ps->topIndex == SIZE)
	{
		return;
	}

	ps->stackArr[ps->topIndex] = n;
	ps->topIndex++;
}

int Pop(pstack ps)
{
	if (ps->topIndex == 0)
	{
		return 0;
	}
	ps->topIndex--;

	return ps->stackArr[ps->topIndex];
}