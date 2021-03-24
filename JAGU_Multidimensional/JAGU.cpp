#include "JAGU.h"

int JAGU::PascalT()
{
	const int cNum = 6;

	int pascal[cNum][cNum] = { 0, };

	for (int i = 0; i < cNum; i++)
	{
		pascal[i][0] = 1;
		for (int j = 0; j < cNum; j++)
		{
			if (j > 0 && i > 0)
				pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
			if (pascal[i][j] > 0)
				cout << pascal[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}

int JAGU::ReverseChar()
{
	const int cNum = 10;

	char word[3][cNum] = { '0', };

	cout << "10글자의 단어를 입력하시오.\n";

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
