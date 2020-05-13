#include <stdio.h>
#include "head.h"
void List_1(LinkList LA);
int main() {
	

	getchar();
	return 0;
}

/***    默认所有链表都带头结点		***/
/***	第二章作业					***/
void mergeList(LinkList *La, LinkList *Lb, LinkList *Lc) {
	LinkList pa, pb, pc;
	pa = (*La)->next;	// 指向La的第一个元素
	pb = (*Lb)->next;	// 指向La的第一个元素
	(*Lc) = pc = (*La);	// Lc使用La的头结点
	while (pa&&pb){
		if (pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {	//因为题目中写出不存在重复元素，所以无需考虑相等情况
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb; //插入剩下的数据
	free((*Lb));  // 释放Lb的头结点
}
void intersectionList(LinkList *La, LinkList *Lb) {
	LinkList pa, pb, pc, t, p;
	pc = (*La);			// pc指向La头结点
	pa = (*La)->next;	// 指向La的第一个元素
	pb = (*Lb)->next;	// 指向La的第一个元素
	while (pa&&pb) {
		if (pa->data < pb->data) {
			t = pa;// 指向即将删除空间的元素
			pa = pa->next;
			free(t); // 释放空间
		}
		else if (pa->next > pb->next) {
			t = pb;// 指向即将删除空间的元素
			pb = pb->next;
			free(t); // 释放空间
		}
		else {
			pc->next = pa;
			pc = pa;
			t = pb; // 指向即将删除空间的元素
			// pa和pb指向下一个元素
			pa = pa->next;
			pb = pb->next;

			free(t); // 释放无用的pb指向的元素，保留pa里的元素
		}
	}
	//释放无用的元素
	p = pa ? pa : pb; // p指向剩余的元素
	while (p) {
		t = p; // 指向即将删除空间的元素
		p = p->next; //指向下一个元素
		free(t);  // 释放空间
	}
}
void func(LinkList *La, LinkList *Lb, LinkList *Lc) {
	LinkList pa,pb,pc;
	
	(*Lb) = (*La); // Lb使用La的头结点
	(*Lc) = (LinkList)malloc(sizeof(struct LNode)); //为Lc申请一个头结点
	pa = (*La)->next; // pa指向La第一个元素
	pb = (*Lb); //pb指向Lb头结点
	pc = (*Lc);//pc指向Lc头结点
	while (pa) {
		if (pa->data < 0) {
			pb->next = pa; // pb所指的元素连接pa所指的元素
			pb = pa; // pb指向Lb的最后一个元素
			pa = pa->next; //pa移动到下一个元素
		}
		else {  // 元素为非零整数,不考虑 ==0情况
			pc->next = pa;// pc所指的元素连接pa所指的元素
			pc = pa; // pc指向Lc的最后一个元素
			pa = pa->next; //pa移动到下一个元素
		}
	}
	// 将Lb和Lc的尾元素的后驱变为NULL
	pb->next = NULL;
	pc->next = NULL;
}
void getBiggestElem(LinkList L, ElemType e) { //ElemType 实现定义为 int
	LinkList p = L->next; //p指向链表第一个元素
	if (!p)
		exit(1);  // 空表退出

	e =  p->data; // 初始默认第一个元素为最大元素
	p = p->next; // p指向下一个元素
	while (p) {
		if (p->data > e)
			e = p->data; // 更改e的值

		p = p->next; // p指向下一个元素
	}
}
void inverse(LinkList L) {
	LinkList p, q;
	p = L->next; // p指向第一个元素
	L->next = NULL;  // 头结点后继变为NULL， 因为有p，所以原先数据未丢失
	while (p) {
		q = p->next; //q指向p的后继
		p->next = L->next; // 重新链接
		L->next = p; //将p插入到头结点之后
		p = q; // p变成下一个元素
	}
}
/*
void delete(SqList L, int n,int item) {
	int *p, *q; 
	q = p = L.elem;  // p、q指向首元素
	for (; q < L.elem + n - 1;q++) {  // p用于指向循环过程中的最后一个有效元素后的位置，q指向正在进行判断的元素
		if (*q != item) {
			*p = *q; // q指向的元素覆盖p指向的元素
			p++;  // p的位置后移
		}
		else  //  与item相等的元素
			L.length--;  // 长度减1
	}
}
*/
