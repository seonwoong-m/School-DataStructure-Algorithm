#include <iostream>

using namespace std;

int main()
{
	char identity1[13];
	int identity2[13];

	cout << "�ֹι�ȣ 13�ڸ� �Է� ( - ����, ���� ���̻��� ���� ���� �ʿ�)\n";

	cin >> identity1;

	for (int i = 0; i < 13; i++) {
		identity2[i] = int(identity1[i] - '0');
	}

	cout << "���� : ";

	if (identity2[6] % 2 == 1)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "��" << endl;
	}

	cout << "���� : ";

	switch (identity2[0])
	{
	case 0:
		cout << 22 - identity2[1];
		break;
	case 1:
		cout << 12 - identity2[1];
		break;
	case 9:
		cout << 10 - identity2[1] + 22;
		break;
	case 8:
		cout << 20 - identity2[1] + 22;
		break;
	case 7:
		cout << 30 - identity2[1] + 22;
		break;
	case 6:
		cout << 40 - identity2[1] + 22;
		break;
	case 5:
		cout << 50 - identity2[1] + 22;
		break;
	default:
		break;
	}

	cout << "��\n";
	cout << "����⵵ : ";

	if (identity2[0] >= 0)
		cout << 20 << identity2[0] << identity2[1];
	else
		cout << 19 << identity2[0] << identity2[1];

	cout << "��\n";
	cout << "������� : ";

	switch (identity2[11])
	{
	case 0:
		if (identity2[12] == 9)
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
		if (identity2[12] < 3)
		{
			cout << "�λ�\n";
			break;
		}
		else if (identity2[12] < 6)
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
		if (identity2[12] < 6)
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
		if (identity2[12] < 5)
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
		if (identity2[12] < 8)
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
		if (identity2[12] < 5)
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
		if (identity2[12] < 7)
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