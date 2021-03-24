//20406 문선웅

#include <iostream>

#define cNum 10

using namespace std;

int main()
{
	
	char word[3][cNum] = { '0', };

	cout << "10자 이내의 단어를 입력하시오.\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < cNum; j++)
		{
			cin >> word[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = cNum - 1; j >= 0; j--)
		{
			cout << word[i][j];
		}
		cout << endl;
	}


	return 0;
}