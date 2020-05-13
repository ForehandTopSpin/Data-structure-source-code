#pragma once

#define MAXQSIZE 5 /* 最大队列长度(对于循环队列，最大队列长度要减1) */
typedef int QElemType;
typedef struct
{
	QElemType *base; /* 初始化的动态分配存储空间 */
	int front; /* 头指针,若队列不空,指向队列头元素 */
	int rear; /* 尾指针,若队列不空,指向队列尾元素的下一个位置 */
}SqQueue;
Status InitQueue(SqQueue *Q);
Status DestroyQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueEmpty(SqQueue Q);
int QueueLength(SqQueue Q);
Status GetHead(SqQueue Q, QElemType *e);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);
Status QueueTraverse(SqQueue Q, void(*vi)(QElemType));
