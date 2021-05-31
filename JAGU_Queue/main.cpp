//#include <iostream>
//
//using namespace std;
//
//#define NEXT(index,QSIZE) ((index + 1) % QSIZE)
//
//typedef struct Queue
//{
//	int* buf;
//	int qsize;
//	int front;
//	int rear;
//	int count;
//}_Queue;
//
//void InitQueue(_Queue* queue, int qsize);
//int IsFull(_Queue* queue);
//int IsEmpty(_Queue* queue);
//void Enqueue(_Queue*, int data);
//int Dequeue(_Queue* queue);
//
//int main()
//{
//	int i;
//	_Queue queue;
//
//	InitQueue(&queue, 10);
//	for (i = 1; i <= 5; i++)
//	{
//		cout << i << "입력\n";
//		Enqueue(&queue, i);
//	}
//
//	cout << endl;
//
//	while (!IsEmpty(&queue))
//	{
//		cout << Dequeue(&queue) << "출력\n";
//	}
//
//	cout << endl;
//
//	return 0;
//}
//
//void InitQueue(_Queue* queue, int qsize)
//{
//	queue->buf = new int[qsize];
//	queue-> qsize = qsize;
//	queue-> front = queue->rear = 0;
//	queue-> count = 0;
//}
//
//int IsFull(_Queue* queue)
//{
//	return queue->count == queue->qsize;
//}
//
//int IsEmpty(_Queue* queue)
//{
//	return queue->count == 0;
//}
//
//void Enqueue(_Queue* queue, int data)
//{
//	if (IsFull(queue))
//	{
//		cout << "큐가 꽉 찼음\n";
//		return;
//	}
//
//	queue->buf[queue->rear] = data;
//	queue->rear = NEXT(queue->rear, queue->qsize);
//	queue->count++;
//}
//
//int Dequeue(_Queue* queue)
//{
//	int re = 0;
//	if (IsEmpty(queue))
//	{
//		cout << "큐가 비었음\n";
//		return re;
//	}
//
//	re = queue->buf[queue->front];
//	queue->front = NEXT(queue->front, queue->qsize);
//	queue->count--;
//	return re;
//}