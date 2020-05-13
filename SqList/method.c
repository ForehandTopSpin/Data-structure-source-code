#include "head.h"
Status InitList(SqList *L) {
	/* 操作结果：构造一个空的顺序线性表 */
	(*L).elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if (!(*L).elem)
		exit(1);  // 空间分配失败
	(*L).length = 0; //  有效数据个数为0
	(*L).listsize = LIST_INIT_SIZE; // 顺序表长度
	return OK;
}
Status DestroyList(SqList *L){
	/* 初始条件：顺序线性表L已存在。操作结果：销毁顺序线性表L */
	free((*L).elem);
	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
	return OK;
}
Status ClearList(SqList *L) {
	/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
	(*L).length = 0;
	return OK;
}
Status ListEmpty(SqList L) {
	/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(SqList L) {
	/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
	return L.length;
}
Status GetElem(SqList L,int i,ElemType *e) {
	/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
   /* 操作结果：用e返回L中第i个数据元素的值 */
	if (i<1 || i>L.length) // 判断 i是否合法
		exit(ERROR);

	*e = *(L.elem + i - 1);
	return OK;
}
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ /* 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1,否则为0) */
  /* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。 */
  /*           若这样的数据元素不存在，则返回值为0。算法2.6 */
	ElemType *p = L.elem;
	int i = 1;  // 被比较元素的位序
	while (i <= L.length && !compare(*p++, e)) {
		++i;
	}
	// 判断是否查找到
	if (i <= L.length) 
		return i;
	else
		return 0;
}
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{ /* 初始条件：顺序线性表L已存在 */
  /* 操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， */
  /*           否则操作失败，pre_e无定义 */
	ElemType *p = L.elem + 1;
	int i = 2;
	while (i<=L.length&&*p!=cur_e){
		++i;
		p++;
	}
	if (i <= L.length) {
		return OK;
		*pre_e = *(--p);  //  返回前驱
	}
	else
		return INFEASIBLE;
}
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{ /* 初始条件：顺序线性表L已存在 */
  /* 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， */
  /*           否则操作失败，next_e无定义 */
	int i = 1;
	ElemType *p = L.elem;
	while (i<L.length&&*p!=cur_e){
		++i;
		++p;
	}

	if (i < L.length) {
		*next_e = *(++p);
		return OK;
	}
	else
		return INFEASIBLE;
}
Status ListInsert(SqList *L, int i, ElemType e)
{ /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1 */
  /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
	ElemType *newBase, *p, *q;
	int j;
	if (i<1 || i>(*L).length + 1) {  // 判断i不合法
		// length+1是因为可以在末尾添加
		return ERROR;
	}

	if ((*L).length >= (*L).listsize) {   //  空间不足，分配空间
		newBase = (ElemType*)realloc((*L).elem, sizeof(ElemType)*((*L).listsize + LISTINCREMENT));
		if (!newBase)  //空间分配失败
			exit(1);
		(*L).elem = newBase;
		(*L).listsize += LISTINCREMENT;
	}
	q = (*L).elem + i - 1;
	for (p = (*L).elem + (*L).length - 1; p >= q; p--) {  //移位
		*(p + 1) = *p;
	}

	*q = e;  //插入
	(*L).length++;  //增加表长

	return OK;
}
Status ListDelete(SqList *L, int i, ElemType *e) 
{ /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
  /* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
	ElemType *p, *q;
	if (i<1 || i>(*L).length) /* i值不合法 */
		return ERROR;

	p = (*L).elem + i - 1; /* p为被删除元素的位置 */
	*e = *p; /* 被删除元素的值赋给e */
	q = (*L).elem + (*L).length - 1; /* 表尾元素的位置 */
	for (++p; p <= q; ++p) /* 被删除元素之后的元素左移 */
		*(p - 1) = *p;

	(*L).length--; /* 表长减1 */
	return OK;
}

Status ListTraverse(SqList L, void(*vi)(ElemType*))
{ /* 初始条件：顺序线性表L已存在 */
  /* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */
  /*           vi()的形参加'&'，表明可通过调用vi()改变元素的值 */
	ElemType *p;
	int i;
	p = L.elem;
	for (i = 1; i <= L.length; i++)
		vi(p++);

	printf("\n");
	return OK;
}
