////20406 ������
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
//	cout << "ù ��° ���ڸ� �Է��Ͻÿ�" << endl;
//	cin >> n;
//
//	cout << "�� ��° ���ڸ� �Է��Ͻÿ�" << endl;
//	cin >> a;
//
//	if (n == a)
//	{
//		cout << "���� �ٸ� ���� �Է��Ͻÿ�" << endl;
//		return main();
//	}
//
//	cout << "�� �� ������ ¦����\n";
//	cout << Even(n, a);
//
//	return 0;
//}