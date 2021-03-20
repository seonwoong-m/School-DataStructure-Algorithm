#include <iostream>

using namespace std;

void changeCharToInt(char identity_char[14], int identity_int[14])
{
	for (int i = 0; i < 14; i++) {
		identity_int[i] = int(identity_char[i] - '0');
	}
}

int main()
{
	char id_char[14];
	int id_int[14];

	cout << "주민번호 13자리 입력 ( - 제외)\n";

	cin >> id_char;

	changeCharToInt(id_char, id_int);

	cout << "성별 : ";

	if (id_int[6] % 2 == 1)
	{
		cout << "남" << endl;
	}
	else
	{
		cout << "여" << endl;
	}

	cout << "나이 : ";

	switch (id_int[0])
	{
	case 0:
		cout << 22 - id_int[1];
		break;
	case 1:
		cout << 12 - id_int[1];
		break;
	case 9:
		cout << 10 - id_int[1] + 22;
		break;
	case 8:
		cout << 20 - id_int[1] + 22;
		break;
	case 7:
		cout << 30 - id_int[1] + 22;
		break;
	case 6:
		cout << 40 - id_int[1] + 22;
		break;
	case 5:
		cout << 50 - id_int[1] + 22;
		break;
	default:
		break;
	}

	cout << "세\n";
	cout << "출생년도 : ";

	if (id_int[0] >= 0)
		cout << 20 << id_int[0] << id_int[1];
	else
		cout << 19 << id_int[0] << id_int[1];

	cout << "년\n";
	cout << "출생지역 : ";

	switch (id_int[11])
	{
	case 0:
		if (id_int[12] == 9)
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
		if (id_int[12] < 3)
		{
			cout << "부산\n";
			break;
		}
		else if (id_int[12] < 6)
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
		if (id_int[12] < 6)
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
		if (id_int[12] < 5)
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
		if (id_int[12] < 8)
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
		if (id_int[12] < 5)
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
		if (id_int[12] < 7)
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