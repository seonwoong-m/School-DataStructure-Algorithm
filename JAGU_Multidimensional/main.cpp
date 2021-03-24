#include "JAGU.h"

int main()
{
	JAGU j;

	int a = 0;

	cout << "파스칼의 삼각형(1)   문자열 역출력(2)" << endl;

	cin >> a;

	if (a == 1)
		j.PascalT();
	else if (a == 2)
		j.ReverseChar();

	return 0;
}