////20406 문선웅
//
//#include <iostream>
//
//using namespace std;
//
//int Even(int n, int a)
//{
//	if (n < a)
//	{
//		if (n < (a - 1))
//		{
//			if ((n % 2) == 0)
//			{
//				cout << n << endl;
//				return Even(n + 1, a);
//			}
//			else
//				return Even(n + 1, a);
//		}
//		else
//		{
//			if ((a % 2) == 0)
//				return a;
//			else
//				return n;
//		}
//	}
//	else if (n > a)
//	{
//		if (a < (n - 1))
//		{
//			if ((a % 2) == 0)
//			{
//				cout << a << endl;
//				return Even(n, a + 1);
//			}
//			else
//				return Even(n, a + 1);
//		}
//		else
//		{
//			if ((n % 2) == 0)
//				return n;
//			else
//				return a;
//		}
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	int n = 0;
//	int a = 0;
//
//	cout << "첫 번째 숫자를 입력하시오" << endl;
//	cin >> n;
//
//	cout << "두 번째 숫자를 입력하시오" << endl;
//	cin >> a;
//
//	if (n == a)
//	{
//		cout << "서로 다른 수를 입력하시오" << endl;
//		return main();
//	}
//
//	cout << "두 수 사이의 짝수는\n";
//	cout << Even(n, a);
//
//	return 0;
//}