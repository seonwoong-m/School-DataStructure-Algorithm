#include <iostream>

using namespace std;

void ChangeCharToInt(char identity_char[14], int identity_int[14])
{
	for (int i = 0; i < 14; i++) {
		identity_int[i] = int(identity_char[i] - '0');
	}
}

int main()
{
	char id_char[14] = { 0, };
	int id_int[14];
	int array[] = { 2,3,4,5,6,7,8,9,2,3,4,5 };
	int sum = 0, check, result;

	cout << "�ֹι�ȣ 13�ڸ� �Է� ( - ����)\n";

	cin >> id_char;

	for (int i = 0; i < 13; i++)
	{
		if (id_char[i] < '0' || id_char[i] > '9')
			cout << "�߸��Է��ϼ̽��ϴ�" << endl;
		break;
	}

	for (int i = 0; i < 12; i++)
	{
		sum += (id_char[i] - '0') * array[i];
	}

	check = id_char[12] - '0';
	result = 11 - (sum % 11);
	result == 10 ? result -= 10 : result;

	if (result == check)
		cout << "��ȿ�� �ֹε�Ϲ�ȣ" << endl;
	else
	{
		cout << "��ȿ���� ���� �ֹε�Ϲ�ȣ" << endl;
		return main();
	}

	ChangeCharToInt(id_char, id_int);

	cout << "���� : ";

	if (id_int[6] % 2 == 1)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "��" << endl;
	}

	cout << "���� : ";

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

	cout << "��\n";
	cout << "����⵵ : ";

	if (id_int[0] == 0)
		cout << 20 << id_int[0] << id_int[1];
	else if(id_int[0] == 9)
		cout << 19 << id_int[0] << id_int[1];

	cout << "��\n";
	cout << "������� : ";


	switch (id_int[11])
	{
	case 0:
		if (id_int[12] == 9)
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
		if (id_int[12] < 3)
		{
			cout << "�λ�\n";
			break;
		}
		else if (id_int[12] < 6)
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
		if (id_int[12] < 6)
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
		if (id_int[12] < 5)
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
		if (id_int[12] < 8)
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
		if (id_int[12] < 5)
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
		if (id_int[12] < 7)
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