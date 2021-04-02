#include <iostream>

using namespace std;

int Reverse(int n)
{
	if (n == 1)
		return 1;
	else
		cout << n << endl;
	return Reverse(n - 1);
}

int main()
{
	int a = 0;

	cin >> a;

	cout << Reverse(a) << endl;

	return 0;
}