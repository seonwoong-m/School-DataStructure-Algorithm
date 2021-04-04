#include <iostream>

using namespace std;

int SumDigit(int n, int a)
{
	if (n <= 0)
		return 0;
	else
	{
		a = a + (n % 10);
		n = (n / 10);
	}

	cout << a << endl;

	return SumDigit(n, a);
}

int main()
{
	int n = 0;
	int a = 0;

	cin >> n;

	cout << SumDigit(n, a);

	return 0;
}