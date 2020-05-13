#include "head.h"

Status visit(TElemType e)
{
	printf("%d ", e);
	return OK;
}
int main() {
	Status i;
	int j;
	position p;
	TElemType e;
	SqBiTree T, s;
	InitBiTree(T);
	CreateBiTree(T);
	printf("������������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	i = Root(T, &e);
	if (i)
		printf("�������ĸ�Ϊ��%d\n", e);
	else
		printf("���գ��޸�\n");
	printf("�������������:\n");
	LevelOrderTraverse(T, visit);
	printf("�������������:\n");
	InOrderTraverse(T, visit);
	printf("�������������:\n");
	PostOrderTraverse(T, visit);
	printf("��������޸Ľ��Ĳ�� �������: ");
	scanf("%d%d", &p.level, &p.order);
	e = Value(T, p);
	printf("���޸Ľ���ԭֵΪ%d��������ֵ: ", e);
	scanf("%d", &e);
	Assign(T, p, e);
	printf("�������������:\n");
	PreOrderTraverse(T, visit);
	printf("���%d��˫��Ϊ%d,���Һ��ӷֱ�Ϊ", e, Parent(T, e));
	printf("%d,%d,�����ֱֵܷ�Ϊ", LeftChild(T, e), RightChild(T, e));
	printf("%d,%d\n", LeftSibling(T, e), RightSibling(T, e));
	InitBiTree(s);
	printf("����������Ϊ�յ���s:\n");
	CreateBiTree(s);
	printf("��s�嵽��T��,��������T����s��˫�׽�� sΪ��(0)����(1)����: ");
	scanf("%d%d", &e, &j);
	InsertChild(T, e, j, s);
	Print(T);
	printf("ɾ������,�������ɾ�����������Ĳ�� ������� ��(0)����(1)����: ");
	scanf("%d%d%d", &p.level, &p.order, &j);
	DeleteChild(T, p, j);
	Print(T);
	ClearBiTree(T);
	printf("�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
	i = Root(T, &e);
	if (i)
		printf("�������ĸ�Ϊ��%d\n", e);
	else
		printf("���գ��޸�\n");



	rewind(stdin);
	getchar();
	return 0;
}