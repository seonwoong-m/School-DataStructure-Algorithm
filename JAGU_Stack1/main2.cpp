//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//	stack<int> s;
//
//	int n = 0;
//	int a = 0;
//	int i = 0;
//
//	cout << "5�ڸ� ������ ���� �Է����ֽʽÿ�" << endl;
//
//	cin >> n;
//
//	if (n > 99999 || n < 0)
//	{
//		cout << "0 �̻��� 5�ڸ� ������ ���� �Է����ֽʽÿ�" << endl;
//	}
//
//	if (n > 9999 && n < 100000)
//		a = 5;
//	else if (n > 999 && n < 10000)
//		a = 4;
//	else if (n > 99 && n < 1000)
//		a = 3;
//	else if (n > 9 && n < 100)
//		a = 2;
//	else if (n >= 0 && n < 10)
//		a = 1;
//
//	while (a != 0)
//	{
//		if (n > 9999 && n < 100000)
//		{
//			s.push(n / 10000);
//			n %= 10000;
//			a--;
//		}
//		else if (n > 999 && n < 10000)
//		{
//			s.push(n / 1000);
//			n %= 1000;
//			a--;
//		}
//		else if (n > 99 && n < 1000)
//		{
//			s.push(n / 100);
//			n %= 100;
//			a--;
//		}
//		else if (n > 9 && n < 100)
//		{
//			s.push(n / 10);
//			n %= 10;
//			a--;
//		}
//		else if (n > 0 && n < 10)
//		{
//			s.push(n);
//			a--;
//		}
//	}
//
//	while (!s.empty())
//	{
//		cout << s.top();
//		s.pop();
//	}
//
//
//	return 0;
//}