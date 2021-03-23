#include <iostream>

using namespace std;

int Factorial(int n)
{
	if (n == 1)
		return 1;

	return (n)*Factorial(n - 1);
}

int main()
{
	int a = 0;

	cin >> a;

	cout << Factorial(a);
}