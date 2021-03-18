#include <iostream>
using namespace std;

int main() {

	int identity[13];

	cout << "주민번호 13자리 입력 ( - 제외, 숫자마다 공백 필요)\n";
	
	for (int i = 0; i < 13; i++)
	{
		cin >> identity[i];
	}
	
	cout << "성별 : ";

	if (identity[6] % 2 == 1)
	{
		cout << "남" << endl;
	}
	else
	{
		cout << "여" << endl;
	}

	cout << "나이 : ";

	switch (identity[0])
	{
	case 0:
		cout << 22 - identity[1];
		break;
	case 1:
		cout << 12 - identity[1];
		break;
	case 9:
		cout << 10 - identity[1] + 22;
		break;
	case 8:
		cout << 20 - identity[1] + 22;
		break;
	case 7:
		cout << 30 - identity[1] + 22;
		break;
	case 6:
		cout << 40 - identity[1] + 22;
		break;
	case 5:
		cout << 50 - identity[1] + 22;
		break;
	default:
		break;
	}

	cout << "세\n";
	cout << "출생년도 : ";
	
	if (identity[0] >= 0)
		cout << 20 << identity[0] << identity[1];
	else
		cout << 19 << identity[0] << identity[1];

	cout << "년\n";
	cout << "출생지역 : ";

	switch (identity[11])
	{
	case 0:
		if (identity[12] == 9)
		{
			cout << "부산\n";
			break;
		}
		else
		{
			cout << "서울\n";
			break;
		}
	case 1:
		if (identity[12] < 3)
		{
			cout << "부산\n";
			break;
		}
		else if (identity[12] < 6)
		{
			cout << "인천\n";
			break;
		}
		else
		{
			cout << "경기도\n";
			break;
		}
	case 2:
		if (identity[12] < 6)
		{
			cout << "경기도\n";
			break;
		}
		else
		{
			cout << "강원도\n";
			break;
		}
	case 3:
		if (identity[12] < 5)
		{
			cout << "강원도\n";
			break;
		}
		else
		{
			cout << "충청북도\n";
			break;
		}
	case 4:
		if (identity[12] < 8)
		{
			cout << "충청남도\n";
			break;
		}
		else
		{
			cout << "전라북도\n";
			break;
		}

	case 5:
		if (identity[12] < 5)
		{
			cout << "전라북도\n";
			break;
		}
		else
		{
			cout << "전라남도\n";
			break;
		}
	case 6:
		if (identity[12] < 7)
		{
			cout << "전라남도\n";
			break;
		}	
		else 
		{
			cout << "경상도\n";
			break;
		}
	default:
		cout << "경상도\n";
		break;

	}

		return 0;
}
