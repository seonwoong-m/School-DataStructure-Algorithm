#include <iostream>

using namespace std;

int ReverseN(int n)
{
	if (n < 10)
		return n;
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