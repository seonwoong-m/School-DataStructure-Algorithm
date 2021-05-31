#include <iostream>
#include <stack>

using namespace std;

stack<int> num;

int main()
{
	int number = 0;
	int temp = 0;

	cout << "0 보다 큰 숫자를 입력하시오\n" << ">> ";
	cin >> number;

	if (number < 0)
	{
		exit(0);
	}
	else
	{
		while (true)
		{
			if (number > 999)
			{
				temp = number % 1000;
				num.push(temp);
				number /= 1000;
			}
			else if (number < 1000 && number >= 0)
			{
				num.push(number);
			}
		}

		while (!num.empty())
		{
			cout << num.top() << ",";
			num.pop();
		}
	}
}