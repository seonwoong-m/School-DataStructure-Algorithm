//#include <iostream>
//
//using namespace std;
//
//#define QUEUE_SIZE 5
//#define NEXT(index) ((index+1)% QUEUE_SIZE)
//
//typedef struct Queue
//{
//	int buf[QUEUE_SIZE];
//	int front;
//	int rear;
//} _Queue;
//
//void InitQueue(_Queue* queue);
//int IsFull(_Queue* queue);
//int IsEmpty(_Queue* queue);
//int Enqueue(_Queue* queue, int data);
//int Dequeue(_Queue* queue);
//
//int main()
//{
//	int select = -1;
//	_Queue queue;
//	InitQueue(&queue);
//
//	while (1)
//	{
//		cout << "1. Enqueue  2. Dequeue" << endl;
//		cout << ">> ";
//		cin >> select;
//		
//		switch (select)
//		{
//		case 1:
//			int value;
//			cout << "Input data : ";
//			cin >> value;
//			Enqueue(&queue, value);
//			break;
//		case 2:
//			Dequeue(&queue);
//			break;
//		}
//		cout << endl;
//	}
//}
//
//void InitQueue(_Queue* queue)
//{
//	queue->front = queue->rear = 0;
//}
//
//int IsFull(_Queue* queue)
//{
//	return NEXT(queue->rear) == queue->front;
//}
//
//int IsEmpty(_Queue* queue)
//{
//	return queue->front == queue->rear;
//}
//
//int Enqueue(_Queue* queue, int data)
//{
//	if (IsFull(queue))
//	{
//		cout << "Å¥°¡ ²Ë Ã¡À½" << endl;
//		return data;
//	}
//	queue->buf[queue->rear] = data;
//	queue->rear = NEXT(queue->rear);
//}
//
//int Dequeue(_Queue* queue)
//{
//	int re = 0;
//	if (IsEmpty(queue))
//	{
//		cout << "Å¥°¡ ºñ¾úÀ½" << endl;
//		return re;
//	}
//
//	re = queue->buf[queue->front];
//	queue->front = NEXT(queue->front);
//	cout << "Dequeue : " << re;
//	return re;
//}