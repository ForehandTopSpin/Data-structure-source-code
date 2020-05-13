#include "head.h"
Status InitStack(LinkStack *L)
{                                              /* 操作结果：构造一个空的线性表L */
	*L = (LinkStack)malloc(sizeof(struct SNode)); /* 产生头结点,并使L指向此头结点 */
	if (!*L)                                     /* 存储分配失败 */
		exit(OVERFLOW);
	(*L)->next = NULL; /* 指针域为空 */
	return OK;
}

Status DestroyStack(LinkStack *L)
{ /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
	LinkStack q;
	while (*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
	return OK;
}

Status ClearStack(LinkStack L) /* 不改变L */
{                            /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
	LinkStack p, q;
	p = L->next; /* p指向第一个结点 */
	while (p)    /* 没到表尾 */
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL; /* 头结点指针域为空 */
	return OK;
}

Status StackEmpty(LinkStack L)
{              /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
	if (L->next) /* 非空 */
		return FALSE;
	else
		return TRUE;
}

int StackLength(LinkStack L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
	int i = 0;
	LinkStack p = L->next; /* p指向第一个结点 */
	while (p)             /* 没到表尾 */
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
		printf("申请空间失败\n");
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
	t = L->next;		//指向栈顶元素
	if (!t)				// 栈为空
		return ERROR;

	//重新连接栈
	p = t->next;
	L->next = p;

	//弹出原栈顶元素
	*e = t->data;   //保存原栈顶元素的数据
	free(t);		//释放栈顶元素
	return OK;
}
Status StackTraverse(LinkStack S, void(*visit)(ElemType))
{ /* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
  /* 不会对原栈造成修改   */	
	ElemType e;
	LinkStack temp, p = S;
	InitStack(&temp); /* 初始化temp栈 */
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
/* vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 */
{ /* 初始条件：线性表L已存在 */
  /* 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
	LinkStack p = L->next;
	while (p)
	{
		vi(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
