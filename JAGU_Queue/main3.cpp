#include <iostream>

using namespace std;

#define NEXT(index, QSIZE) ((index+1)% QSIZE)

typedef struct Queue
{
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;
} _Queue;

void InitQueue(_Queue* queue, int qsize);
int IsFull(_Queue* queue);
int IsEmpty(_Queue* queue);
int Enqueue(_Queue* queue, int data);
int Dequeue(_Queue* queue);

int main()
{
	int i, size;
	int select = -1;
	
	_Queue queue;

	cout << "큐의 크기를 입력하세요. : ";
	cin >> size;

	InitQueue(&queue, size);

	while (1)
	{
		cout << "1. Enqueue  2. Dequeue" << endl;
		cout << ">> ";
		cin >> select;

		switch (select)
		{
		case 1:
			int value;
			cout << "Input data : ";
			cin >> value;
			Enqueue(&queue, value);
			break;

		case 2:
			Dequeue(&queue);
			break;
		}

		cout << endl;
	}
}

void InitQueue(_Queue* queue, int qsize)
{
	queue->buf = new int[qsize];
	queue->qsize = qsize;
	queue->front = queue->rear = 0;
	queue->count = 0;
}

int IsFull(_Queue* queue)
{
	return queue->count == queue->qsize;
}

int IsEmpty(_Queue* queue)
{
	return queue->count == 0;
}

int Enqueue(_Queue* queue, int data)
{
	if (IsFull(queue))
	{
		cout << "큐가 꽉 찼음" << endl;
		return data;
	}
	queue->buf[queue->rear] = data;
	queue->rear = NEXT(queue->rear, queue->qsize);
	queue->count++;
}

int Dequeue(_Queue* queue)
{
	int re = 0;
	if (IsEmpty(queue))
	{
		cout << "큐가 비었음" << endl;
		return re;
	}

	re = queue->buf[queue->front];
	queue->front = NEXT(queue->front, queue->qsize);
	cout << "Dequeue : " << re;
	queue->count--;
	return re;
}