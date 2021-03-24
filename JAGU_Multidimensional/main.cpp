#include <iostream>

using namespace std;

int main()
{
	const int cNum = 4;

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