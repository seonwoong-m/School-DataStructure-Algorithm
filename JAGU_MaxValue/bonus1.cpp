#include <iostream>

using namespace std;

int SumDigit(int n, int a)
{
	if (n <= 0)
		return a;
	else
	{
		a = a + (n % 10);
		n = (n / 10);
	}

	return SumDigit(n, a);
}

int main()
{
	int n = 0;
	int a = 0;

	cout << "네 자리 이상의 수를 입력하시오" << endl;

	cin >> n;

	if (n <= 999)
	{
		return main();
	}

	cout << SumDigit(n, a);

	return 0;
}