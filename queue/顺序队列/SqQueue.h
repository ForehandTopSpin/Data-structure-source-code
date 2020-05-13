#pragma once

#define MAXQSIZE 5 /* �����г���(����ѭ�����У������г���Ҫ��1) */
typedef int QElemType;
typedef struct
{
	QElemType *base; /* ��ʼ���Ķ�̬����洢�ռ� */
	int front; /* ͷָ��,�����в���,ָ�����ͷԪ�� */
	int rear; /* βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� */
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
