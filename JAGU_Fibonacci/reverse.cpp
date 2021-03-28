#include <iostream>

using namespace std;

int ReverseN(int n)
{
	if (n == 0)
		return 0;
	else
	{
		cout << n % 10;
		n/= 10;
		return ReverseN(n);
	}
}


int main()
{
	int n = 0;

	cin >> n;

	cout << ReverseN(n);
}