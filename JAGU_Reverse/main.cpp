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

	if (a <= 0)
	{
		cout << "1 이상의 수를 입력하시오" << endl;
		return main();
	}

	cout << Reverse(a) << endl;

	return 0;
}