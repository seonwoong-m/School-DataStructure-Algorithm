#include "JAGU.h"

int main()
{
	JAGU j;

	int a = 0;
	int n = 0;
	
	cout << "���콺 ����(���� O)(1) ���콺 ����(���� X)(2) ���丮��(����Լ� O)(3) ���丮��(����Լ� X)(4)\n";

	cin >> a;


	if (a == 1)
	{
		cout << "1���� ����� ���� ������ �Է��Ͻÿ�\n";
		cin >> n;
		cout << j.Gauss(n) << endl;
		return 0;
	}
	else if (a == 2)
	{
		cout << "1���� ����� ���� ������ �Է��Ͻÿ�\n";
		cin >> n;
		cout << j.Gauss2(n) << endl;
		return 0;
	}
	else if (a == 3)
	{
		cout << "�� ���丮���� ���� ������ �Է��Ͻÿ�\n";
		cin >> n;
		cout << n << "! = " << j.Factorial(n) << endl;
		return 0;
	}
	else if (a == 4)
	{
		cout << "�� ���丮���� ���� ������ �Է��Ͻÿ�\n";
		cin >> n;
		cout << n << "! = " << j.Factorial2(n) << endl;
		return 0;
	}
	else
	{
		cout << "1���� 4���� �߿��� �Է��Ͻÿ�\n";
		main();		
	}

	return 0;
}