//#include <iostream>
//
//using namespace std;
//
//void TowerOfHanoi(int n, char s, char a, char b)
//{
//	if (n == 1)
//		cout << "���� 1�� " << s << "���� " << b << "�� �̵�" << endl;
//	else
//	{
//		TowerOfHanoi(n - 1, s, b, a);
//		cout << "���� " << n << "��" << s << "���� " << b << "�� �̵�" << endl;
//		TowerOfHanoi(n - 1, a, s, b);
//
//
//	}
//}
//
//int main()
//{
//	int n;
//	char s;
//	char a;
//	char b;
//
//	cin >> n >> s >> a >> b;
//
//	TowerOfHanoi(n, s, a, b);
//
//	return 0;
//}