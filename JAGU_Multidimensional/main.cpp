#include "JAGU.h"

int main()
{
	JAGU j;

	int a = 0;

	cout << "�Ľ�Į�� �ﰢ��(1)   ���ڿ� �����(2)" << endl;

	cin >> a;

	if (a == 1)
		j.PascalT();
	else if (a == 2)
		j.ReverseChar();

	return 0;
}