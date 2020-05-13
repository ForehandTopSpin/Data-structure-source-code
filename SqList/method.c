#include "head.h"
Status InitList(SqList *L) {
	/* �������������һ���յ�˳�����Ա� */
	(*L).elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if (!(*L).elem)
		exit(1);  // �ռ����ʧ��
	(*L).length = 0; //  ��Ч���ݸ���Ϊ0
	(*L).listsize = LIST_INIT_SIZE; // ˳�����
	return OK;
}
Status DestroyList(SqList *L){
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L */
	free((*L).elem);
	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
	return OK;
}
Status ClearList(SqList *L) {
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
	(*L).length = 0;
	return OK;
}
Status ListEmpty(SqList L) {
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}
int ListLength(SqList L) {
	/* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
	return L.length;
}
Status GetElem(SqList L,int i,ElemType *e) {
	/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
   /* �����������e����L�е�i������Ԫ�ص�ֵ */
	if (i<1 || i>L.length) // �ж� i�Ƿ�Ϸ�
		exit(ERROR);

	*e = *(L.elem + i - 1);
	return OK;
}
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{ /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
  /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
  /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6 */
	ElemType *p = L.elem;
	int i = 1;  // ���Ƚ�Ԫ�ص�λ��
	while (i <= L.length && !compare(*p++, e)) {
		++i;
	}
	// �ж��Ƿ���ҵ�
	if (i <= L.length) 
		return i;
	else
		return 0;
}
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{ /* ��ʼ������˳�����Ա�L�Ѵ��� */
  /* �����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ���� */
  /*           �������ʧ�ܣ�pre_e�޶��� */
	ElemType *p = L.elem + 1;
	int i = 2;
	while (i<=L.length&&*p!=cur_e){
		++i;
		p++;
	}
	if (i <= L.length) {
		return OK;
		*pre_e = *(--p);  //  ����ǰ��
	}
	else
		return INFEASIBLE;
}
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{ /* ��ʼ������˳�����Ա�L�Ѵ��� */
  /* �����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣� */
  /*           �������ʧ�ܣ�next_e�޶��� */
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
{ /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 */
  /* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
	ElemType *newBase, *p, *q;
	int j;
	if (i<1 || i>(*L).length + 1) {  // �ж�i���Ϸ�
		// length+1����Ϊ������ĩβ���
		return ERROR;
	}

	if ((*L).length >= (*L).listsize) {   //  �ռ䲻�㣬����ռ�
		newBase = (ElemType*)realloc((*L).elem, sizeof(ElemType)*((*L).listsize + LISTINCREMENT));
		if (!newBase)  //�ռ����ʧ��
			exit(1);
		(*L).elem = newBase;
		(*L).listsize += LISTINCREMENT;
	}
	q = (*L).elem + i - 1;
	for (p = (*L).elem + (*L).length - 1; p >= q; p--) {  //��λ
		*(p + 1) = *p;
	}

	*q = e;  //����
	(*L).length++;  //���ӱ�

	return OK;
}
Status ListDelete(SqList *L, int i, ElemType *e) 
{ /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
  /* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
	ElemType *p, *q;
	if (i<1 || i>(*L).length) /* iֵ���Ϸ� */
		return ERROR;

	p = (*L).elem + i - 1; /* pΪ��ɾ��Ԫ�ص�λ�� */
	*e = *p; /* ��ɾ��Ԫ�ص�ֵ����e */
	q = (*L).elem + (*L).length - 1; /* ��βԪ�ص�λ�� */
	for (++p; p <= q; ++p) /* ��ɾ��Ԫ��֮���Ԫ������ */
		*(p - 1) = *p;

	(*L).length--; /* ����1 */
	return OK;
}

Status ListTraverse(SqList L, void(*vi)(ElemType*))
{ /* ��ʼ������˳�����Ա�L�Ѵ��� */
  /* ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ�� */
  /*           vi()���βμ�'&'��������ͨ������vi()�ı�Ԫ�ص�ֵ */
	ElemType *p;
	int i;
	p = L.elem;
	for (i = 1; i <= L.length; i++)
		vi(p++);

	printf("\n");
	return OK;
}
