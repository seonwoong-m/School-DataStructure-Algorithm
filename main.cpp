#include <iostream>
using namespace std;

int main() {
	// your code goes here

	int identity[13];

	cout << "�ֹι�ȣ 13�ڸ� �Է� ( - ����, ���ڸ��� ���� �ʿ�)\n";
	
	for (int i = 0; i < 13; i++)
	{
		cin >> identity[i];
	}
	
	cout << "���� : ";

	if (identity[6] % 2 == 1)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "��" << endl;
	}

	cout << "���� : ";

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

	cout << "��\n";
	cout << "����⵵ : ";
	
	if (identity[0] >= 0)
		cout << 20 << identity[0] << identity[1];
	else
		cout << 19 << identity[0] << identity[1];

	cout << "��\n";
	cout << "������� : ";

	switch (identity[11])
	{
	case 0:
		if (identity[12] == 9)
		{
			cout << "�λ�\n";
			break;
		}
		else
		{
			cout << "����\n";
			break;
		}
	case 1:
		if (identity[12] < 3)
		{
			cout << "�λ�\n";
			break;
		}
		else if (identity[12] < 6)
		{
			cout << "��õ\n";
			break;
		}
		else
		{
			cout << "��⵵\n";
			break;
		}
	case 2:
		if (identity[12] < 6)
		{
			cout << "��⵵\n";
			break;
		}
		else
		{
			cout << "������\n";
			break;
		}
	case 3:
		if (identity[12] < 5)
		{
			cout << "������\n";
			break;
		}
		else
		{
			cout << "��û�ϵ�\n";
			break;
		}
	case 4:
		if (identity[12] < 8)
		{
			cout << "��û����\n";
			break;
		}
		else
		{
			cout << "����ϵ�\n";
			break;
		}

	case 5:
		if (identity[12] < 5)
		{
			cout << "����ϵ�\n";
			break;
		}
		else
		{
			cout << "���󳲵�\n";
			break;
		}
	case 6:
		if (identity[12] < 7)
		{
			cout << "���󳲵�\n";
			break;
		}	
		else 
		{
			cout << "���\n";
			break;
		}
	default:
		cout << "���\n";
		break;

	}

		return 0;
}