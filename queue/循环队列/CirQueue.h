
/* ���е�˳��洢�ṹ(������ѭ�����кͷ�ѭ������) */
typedef int QElemType;
#define MAXQSIZE 5 /* �����г���(����ѭ�����У������г���Ҫ��m) */
typedef struct
{
	QElemType *base; /* ��ʼ���Ķ�̬����洢�ռ� */
	int front; /* ͷָ��,�����в���,ָ�����ͷԪ�� */
	int rear; /* βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� */
}CirQueue;
Status InitQueue(CirQueue *Q);
Status DestroyQueue(CirQueue *Q);
Status ClearQueue(CirQueue *Q);
Status QueueEmpty(CirQueue Q);
int QueueLength(CirQueue Q);
Status GetHead(CirQueue Q, QElemType *e);
Status EnQueue(CirQueue *Q, QElemType e);
Status DeQueue(CirQueue *Q, QElemType *e);
Status QueueTraverse(CirQueue Q, void(*vi)(QElemType));