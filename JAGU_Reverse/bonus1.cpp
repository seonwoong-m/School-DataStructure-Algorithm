//#include <iostream>
//
//using namespace std;
//
//int Odd(int n, int a)
//{
//	if (n < a)
//	{
//		if (n < (a - 1))
//		{
//			if ((n % 2) == 1)
//			{
//				cout << n << endl;
//				return Odd(n + 1, a);
//			}
//			else
//				return Odd(n + 1, a);
//		}
//		else
//		{
//			if ((a % 2) == 1)
//				return a;
//			else
//				return n;
//		}
//	}
//	else if (n > a)
//	{
//		if (a < (n - 1))
//		{
//			if ((a % 2) == 1)
//			{
//				cout << a << endl;
//				return Odd(n, a + 1);
//			}
//			else
//				return Odd(n, a + 1);
//		}
//		else
//		{
//			if ((n % 2) == 1)
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
//	cout << "ù ��° ���ڸ� �Է��Ͻÿ�" << endl;
//	cin >> n;
//
//	cout << "�� ��° ���ڸ� �Է��Ͻÿ�" << endl;
//	cin >> a;
//
//	cout << "�� �� ������ Ȧ����\n";
//	cout << Odd(n, a);
//
//	return 0;
//}