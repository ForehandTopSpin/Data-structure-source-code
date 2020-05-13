#pragma once
#include "head.h"
Status InitList(SqList *L);
Status DestroyList(SqList *L);
Status ClearList(SqList *L);
Status ListEmpty(SqList L);
int ListLength(SqList L);
Status GetElem(SqList L, int i, ElemType *e);
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
Status ListTraverse(SqList L, void(*vi)(ElemType*));

