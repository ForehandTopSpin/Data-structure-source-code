#pragma once

#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef BiTree SElemType;   /* 设栈元素为二叉树的指针类型 */

typedef struct SqStack
{
	SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
	SElemType *top; /* 栈顶指针 */
	int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

Status InitStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType *e);
Status Push(SqStack *S, SElemType e);
Status Pop(SqStack *S, SElemType *e);
Status StackTraverse(SqStack S, Status(*visit)(SElemType));
