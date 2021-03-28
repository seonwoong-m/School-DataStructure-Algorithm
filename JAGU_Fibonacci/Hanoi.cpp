//#include <iostream>
//
//using namespace std;
//
//void TowerOfHanoi(int n, char s, char a, char b)
//{
//	if (n == 1)
//		cout << "원반 1을 " << s << "에서 " << b << "로 이동" << endl;
//	else
//	{
//		TowerOfHanoi(n - 1, s, b, a);
//		cout << "원반 " << n << "을" << s << "에서 " << b << "로 이동" << endl;
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