/* 链栈的结构定义和单链表结构定义相同 */
#include "head.h"
typedef int ElemType;
typedef struct SNode
{
	ElemType data;
	struct SNode *next;
}SNode, *LinkStack;

Status InitStack(LinkStack *L);
Status DestroyStack(LinkStack *L);
Status ClearStack(LinkStack L);
Status StackEmpty(LinkStack L);
int StackLength(LinkStack L);
Status GetTop(LinkStack L,ElemType *e);
Status Push(LinkStack L ,ElemType e);
Status Pop(LinkStack L, ElemType *e);
Status StackTraverse(LinkStack L, void(*vi)(ElemType));
Status ListTraverse(LinkStack L, void(*vi)(ElemType));