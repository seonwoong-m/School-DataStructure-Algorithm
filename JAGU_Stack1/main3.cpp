#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> s;
	int a, b, c;

	cin >> a >> b >> c;

	s.push(a);
	s.push(b);
	s.push(c);

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}

	return 0;
}