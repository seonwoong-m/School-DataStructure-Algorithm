#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<char> s1;
	stack<int> s2;
	int n = 0;
	int a = 0;
	int b = 0;;

	cin >> n;

	b = n;

	while (true)
	{
		if (b <= 0)
		{
			a++;
			break;
		}
		else
		{
			b /= 1000;
			a++;
		}
	}

	for (int i = 0; i < a; i++)
	{
		if (n >= 1000)
		{
			s2.push(n % 1000);
			s1.push(',');
			n /= 1000;
		}
		else if(n < 1000)
		{
			s2.push(n);
		}
	}

	for (int i = 0; i < a; i++)
	{
		cout << s2.top() << s1.top();
		s1.pop();
		s2.pop();
	}


}