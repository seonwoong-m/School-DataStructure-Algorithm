#include "JAGU.h"

int main()
{
	JAGU j;

	int a = 0;
	int n = 0;
	
	cout << "가우스 덧셈(공식 O)(1) 가우스 덧셈(공식 X)(2) 팩토리얼(재귀함수 O)(3) 팩토리얼(재귀함수 X)(4)\n";

	cin >> a;


	if (a == 1)
	{
		cout << "1부터 몇까지 더할 것인지 입력하시오\n";
		cin >> n;
		cout << j.Gauss(n) << endl;
		return 0;
	}
	else if (a == 2)
	{
		cout << "1부터 몇까지 더할 것인지 입력하시오\n";
		cin >> n;
		cout << j.Gauss2(n) << endl;
		return 0;
	}
	else if (a == 3)
	{
		cout << "몇 팩토리얼을 구할 것인지 입력하시오\n";
		cin >> n;
		cout << n << "! = " << j.Factorial(n) << endl;
		return 0;
	}
	else if (a == 4)
	{
		cout << "몇 팩토리얼을 구할 것인지 입력하시오\n";
		cin >> n;
		cout << n << "! = " << j.Factorial2(n) << endl;
		return 0;
	}
	else
	{
		cout << "1부터 4까지 중에서 입력하시오\n";
		main();		
	}

	return 0;
}