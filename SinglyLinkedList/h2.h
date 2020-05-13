#pragma once

typedef int ElemType;
struct LNode
{
	ElemType data;
	struct LNode *next;
};
typedef struct LNode *LinkList; /* 另一种定义LinkList的方法 */