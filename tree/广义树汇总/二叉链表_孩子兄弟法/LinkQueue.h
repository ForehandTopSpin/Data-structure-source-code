#pragma once
typedef CSTree QElemType; /* 定义队列元素类型 */
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;
Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
Status GetHead_Q(LinkQueue Q, QElemType *e);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);
Status QueueTraverse(LinkQueue Q, void(*vi)(QElemType));
