//#include <iostream>
//
//using namespace std;
//
//int MultiplicationTable(int n, int a)
//{
//	if (a == 9)
//	{
//		cout << n << " * " << 9 << " = ";
//		return n * 9;
//	}
//		
//	else
//	{
//		cout << n << " * " << a << " = ";
//		cout << (n * a) << endl;	
//	}
//	return MultiplicationTable(n, a + 1);
//}
//
//int main()
//{
//	int n = 0;
//	int a = 1;
//
//	cout << "몇 단을 출력하시겠습니까?\n";
//
//	cin >> n;
//
//	if (n <= 0)
//	{
//		cout << "1이상의 수만 써주십시오" << endl;
//		return main();
//	}
//
//	cout << endl;
//	cout << "구구단\n";
//	cout << MultiplicationTable(n, a) << endl;
//
//	return 0;
//}