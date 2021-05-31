//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//stack<int> s;
//
//int main()
//{
//	int n;
//
//	cout << "숫자를 입력하시오\n" << ">> ";
//
//	cin >> n;
//
//	while (n != 0)
//	{
//		if (n >= 10)
//		{
//			if ((n % 10) == 0)
//			{
//				s.push(0);
//			}
//			else
//			{
//				s.push(n % 10);
//			}
//		}
//		else
//		{
//			s.push(n);
//		}
//
//		n /= 10;
//	}
//
//	if ((s.size() % 3) == 0)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			cout << s.top();
//			s.pop();
//		}
//	}
//	else if ((s.size() % 3) == 1)
//	{
//		cout << s.top();
//		s.pop();
//	}
//	else if ((s.size() % 3) == 2)
//	{
//		for (int i = 0; i < 2; i++)
//		{
//			cout << s.top();
//			s.pop();
//		}
//	}
//
//	while (!s.empty())
//	{
//		cout << ",";
//		for (int i = 0; i < 3; i++)
//		{
//			cout << s.top();
//			s.pop();
//		}
//	}
//
//	return (0);
//}