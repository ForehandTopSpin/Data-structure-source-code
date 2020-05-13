#include <stdio.h>
#include "head.h"
void List_1(LinkList LA);
int main() {
	

	getchar();
	return 0;
}

/***    Ĭ������������ͷ���		***/
/***	�ڶ�����ҵ					***/
void mergeList(LinkList *La, LinkList *Lb, LinkList *Lc) {
	LinkList pa, pb, pc;
	pa = (*La)->next;	// ָ��La�ĵ�һ��Ԫ��
	pb = (*Lb)->next;	// ָ��La�ĵ�һ��Ԫ��
	(*Lc) = pc = (*La);	// Lcʹ��La��ͷ���
	while (pa&&pb){
		if (pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {	//��Ϊ��Ŀ��д���������ظ�Ԫ�أ��������迼��������
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; //����ʣ�µ�����
	free((*Lb));  // �ͷ�Lb��ͷ���
}
void intersectionList(LinkList *La, LinkList *Lb) {
	LinkList pa, pb, pc, t, p;
	pc = (*La);			// pcָ��Laͷ���
	pa = (*La)->next;	// ָ��La�ĵ�һ��Ԫ��
	pb = (*Lb)->next;	// ָ��La�ĵ�һ��Ԫ��
	while (pa&&pb) {
		if (pa->data < pb->data) {
			t = pa;// ָ�򼴽�ɾ���ռ��Ԫ��
			pa = pa->next;
			free(t); // �ͷſռ�
		}
		else if (pa->next > pb->next) {
			t = pb;// ָ�򼴽�ɾ���ռ��Ԫ��
			pb = pb->next;
			free(t); // �ͷſռ�
		}
		else {
			pc->next = pa;
			pc = pa;
			t = pb; // ָ�򼴽�ɾ���ռ��Ԫ��
			// pa��pbָ����һ��Ԫ��
			pa = pa->next;
			pb = pb->next;

			free(t); // �ͷ����õ�pbָ���Ԫ�أ�����pa���Ԫ��
		}
	}
	//�ͷ����õ�Ԫ��
	p = pa ? pa : pb; // pָ��ʣ���Ԫ��
	while (p) {
		t = p; // ָ�򼴽�ɾ���ռ��Ԫ��
		p = p->next; //ָ����һ��Ԫ��
		free(t);  // �ͷſռ�
	}
}
void func(LinkList *La, LinkList *Lb, LinkList *Lc) {
	LinkList pa,pb,pc;
	
	(*Lb) = (*La); // Lbʹ��La��ͷ���
	(*Lc) = (LinkList)malloc(sizeof(struct LNode)); //ΪLc����һ��ͷ���
	pa = (*La)->next; // paָ��La��һ��Ԫ��
	pb = (*Lb); //pbָ��Lbͷ���
	pc = (*Lc);//pcָ��Lcͷ���
	while (pa) {
		if (pa->data < 0) {
			pb->next = pa; // pb��ָ��Ԫ������pa��ָ��Ԫ��
			pb = pa; // pbָ��Lb�����һ��Ԫ��
			pa = pa->next; //pa�ƶ�����һ��Ԫ��
		}
		else {  // Ԫ��Ϊ��������,������ ==0���
			pc->next = pa;// pc��ָ��Ԫ������pa��ָ��Ԫ��
			pc = pa; // pcָ��Lc�����һ��Ԫ��
			pa = pa->next; //pa�ƶ�����һ��Ԫ��
		}
	}
	// ��Lb��Lc��βԪ�صĺ�����ΪNULL
	pb->next = NULL;
	pc->next = NULL;
}
void getBiggestElem(LinkList L, ElemType e) { //ElemType ʵ�ֶ���Ϊ int
	LinkList p = L->next; //pָ�������һ��Ԫ��
	if (!p)
		exit(1);  // �ձ��˳�

	e =  p->data; // ��ʼĬ�ϵ�һ��Ԫ��Ϊ���Ԫ��
	p = p->next; // pָ����һ��Ԫ��
	while (p) {
		if (p->data > e)
			e = p->data; // ����e��ֵ

		p = p->next; // pָ����һ��Ԫ��
	}
}
void inverse(LinkList L) {
	LinkList p, q;
	p = L->next; // pָ���һ��Ԫ��
	L->next = NULL;  // ͷ����̱�ΪNULL�� ��Ϊ��p������ԭ������δ��ʧ
	while (p) {
		q = p->next; //qָ��p�ĺ��
		p->next = L->next; // ��������
		L->next = p; //��p���뵽ͷ���֮��
		p = q; // p�����һ��Ԫ��
	}
}
/*
void delete(SqList L, int n,int item) {
	int *p, *q; 
	q = p = L.elem;  // p��qָ����Ԫ��
	for (; q < L.elem + n - 1;q++) {  // p����ָ��ѭ�������е����һ����ЧԪ�غ��λ�ã�qָ�����ڽ����жϵ�Ԫ��
		if (*q != item) {
			*p = *q; // qָ���Ԫ�ظ���pָ���Ԫ��
			p++;  // p��λ�ú���
		}
		else  //  ��item��ȵ�Ԫ��
			L.length--;  // ���ȼ�1
	}
}
*/
