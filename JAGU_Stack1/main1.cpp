#include <iostream>

using namespace std;

#define SIZE 10

typedef struct
{
	char stackArr[SIZE];
	int topIndex;
	char name;
}_stack;

typedef _stack* pstack;

void Init(pstack ps, char c);
void Push(pstack ps, char ch);
char Pop(pstack ps);

int main()
{
	_stack s1, s2;
	int i;

	Init(&s1, 'A');
	Init(&s2, 'B');

	cout << endl;

	Push(&s1, 'd');
	Push(&s1, 'a');
	Push(&s1, 't');
	Push(&s1, 'a');

	Push(&s2, 's');
	Push(&s2, 't');
	Push(&s2, 'a');
	Push(&s2, 'c');
	Push(&s2, 'k');

	for (i = 0; i < 5; i++)
	{
		cout << "Pop s1 : " << Pop(&s1) << endl;
	}

	cout << endl;

	for (i = 0; i < 5; i++)
	{
		cout << "Pop s2 : " << Pop(&s2) << endl;
	}

	return 0;
}

void Init(pstack ps, char c)
{
	ps->topIndex = 0;
	ps->name = c;
	cout << "Constructing stack " << ps->name << endl;
}
void Push(pstack ps, char ch)
{
	if (ps->topIndex == SIZE)
	{
		cout << "Stack " << ps->name << " is full" << endl;
		return;
	}

	ps->stackArr[ps->topIndex] = ch;
	ps->topIndex++;
}

char Pop(pstack ps)
{
	if (ps->topIndex == 0)
	{
		cout << "Stack " << ps->name << " is empty" << endl;
	}
	ps->topIndex--;

	return ps->stackArr[ps->topIndex];
}