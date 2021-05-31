//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//stack<string> s;
//
//int main()
//{
//	int n = 0;
//	string str;
//
//	cout << "몇 개의 데이터를 입력하시겠습니까?\n" << ">> ";
//
//	cin >> n;
//
//	while (n > 1000)
//	{
//		cout << "1000 이하의 수를 입력하시오\n" << ">> ";
//		cin >> n;
//	}
//
//	for (int i = n; i > 0; i--)
//	{
//		cin >> str;
//		s.push(str);
//	}
//
//	for (int i = n; i > 0; i--)
//	{
//		cout << s.top() << endl;
//		s.pop();
//	}
//
//	return (0);
//}