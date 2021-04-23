#include <iostream>

using namespace std;

typedef struct linked
{
	int data;
	struct linked* next;
}_node;

_node* head = NULL;
_node* tail = NULL;

void Init();
void Insert(_node* ptr);
void PrintList(_node* ptr);
void InsertData(_node* ptr);
void Delete(_node* ptr);

int main()
{
	int menu = 0;

	Init();
	while (true)
	{
		cout << "1. �Է� 2. ��� 3. ���� 4. ���� 5. ����" << endl;
		cout << "Input menu : ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			Insert(tail);
			break;
		case 2:
			PrintList(head);
			break;
		case 3:
			InsertData(head);
			break;
		case 4:
			Delete(head);
			break;
		case 5:
			cout << "�����մϴ�";
			exit(0);
			
		default:
			cout << "Select menu error.." << endl;
		}

		if (menu == 6) break;
	}

	return 0;
}

void Init()
{
	head = new _node;

	head->data = 0;
	head->next = NULL;

	tail = head;

	return;
}
void Insert(_node* ptr)
{
	_node* newnode = new _node;
	int num = 0;

	cout << "Input number : ";
	cin >> num;

	newnode->data = num;
	newnode->next = NULL;

	ptr->next = newnode;
	tail = newnode;

	return;
}
void PrintList(_node* ptr)
{
	_node* view = ptr->next;

	while (view != NULL)
	{
		cout << view->data;
		view = view->next;
	}

	cout << endl;

	return;
}

void InsertData(_node* ptr)
{
	_node* newnode = new _node;

	int index = 0;
	int num = 0;
	int i;

	cout << "Input InsertData index : ";
	cin >> index;
	
	cout << "Input data : ";
	cin >> num;

	for (i = 0; i < index; i++)
	{
		ptr = ptr->next;
	}

	newnode->data = num;
	newnode->next = NULL;

	if (ptr->next == NULL)
	{
		ptr->next = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = ptr->next;
		ptr->next = newnode;
	}

	return;
}

void Delete(_node* ptr)
{
	_node* temp = 0;
	int i;
	int index;

	if (head == tail)
	{
		cout << "Not found data" << endl;
		return;
	}

	cout << "Input delete index : ";
	cin >> index;

	for (i = 0; i < index - 1; i++)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;

	if (temp->next == NULL)
	{
		ptr->next = NULL;
		tail = ptr;
	}
	else
	{
		ptr->next = temp->next;
	}

	delete(temp);
	return;
}