#include "head.h"
Status InitStack(LinkStack *L)
{                                              /* �������������һ���յ����Ա�L */
	*L = (LinkStack)malloc(sizeof(struct SNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
	if (!*L)                                     /* �洢����ʧ�� */
		exit(OVERFLOW);
	(*L)->next = NULL; /* ָ����Ϊ�� */
	return OK;
}

Status DestroyStack(LinkStack *L)
{ /* ��ʼ���������Ա�L�Ѵ��ڡ�����������������Ա�L */
	LinkStack q;
	while (*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
	return OK;
}

Status ClearStack(LinkStack L) /* ���ı�L */
{                            /* ��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
	LinkStack p, q;
	p = L->next; /* pָ���һ����� */
	while (p)    /* û����β */
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL; /* ͷ���ָ����Ϊ�� */
	return OK;
}

Status StackEmpty(LinkStack L)
{              /* ��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	if (L->next) /* �ǿ� */
		return FALSE;
	else
		return TRUE;
}

int StackLength(LinkStack L)
{ /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
	int i = 0;
	LinkStack p = L->next; /* pָ���һ����� */
	while (p)             /* û����β */
	{
		i++;
		p = p->next;
	}
	return i;
}

Status GetTop(LinkStack L, ElemType *e) 
{                                             
	if (L->next) {
		*e = L->next->data;
		return OK;
	}
	else
	{
		return ERROR;
	}
}



Status Push(LinkStack L, ElemType e) 
{                                                
	LinkStack p;
	p = (LinkStack)malloc(sizeof(SNode));
	if (!p) {
		printf("����ռ�ʧ��\n");
		return ERROR;
	}
	p->data = e;
	p->next = L->next;
	L->next = p;
	return OK;
}

Status Pop(LinkStack L, ElemType *e) 
{                                             
	LinkStack p, t;
	t = L->next;		//ָ��ջ��Ԫ��
	if (!t)				// ջΪ��
		return ERROR;

	//��������ջ
	p = t->next;
	L->next = p;

	//����ԭջ��Ԫ��
	*e = t->data;   //����ԭջ��Ԫ�ص�����
	free(t);		//�ͷ�ջ��Ԫ��
	return OK;
}
Status StackTraverse(LinkStack S, void(*visit)(ElemType))
{ /* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()�� */
  /* �����ԭջ����޸�   */	
	ElemType e;
	LinkStack temp, p = S;
	InitStack(&temp); /* ��ʼ��tempջ */
	while (p->next)
	{
		GetTop(p, &e);
		Push(temp, e);
		p = p->next;
	}
	ListTraverse(temp, visit);
	return OK;
}
Status ListTraverse(LinkStack L, void(*vi)(ElemType))
/* vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ */
{ /* ��ʼ���������Ա�L�Ѵ��� */
  /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
	LinkStack p = L->next;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
