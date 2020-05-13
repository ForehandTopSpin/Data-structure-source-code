#include "head.h"
Status visit(VertexType v)
{
	printf("%s ", v);
	return OK;
}

int main()
{
	int k, n;
	AMLGraph g;
	VertexType v1, v2;
	CreateGraph(&g);
	Display(g);
	printf("�޸Ķ����ֵ��������ԭֵ ��ֵ: ");
	scanf("%s%s", v1, v2);
	PutVex(&g, v1, v2);
	printf("�����¶��㣬�����붥���ֵ: ");
	scanf("%s", v1);
	InsertVex(&g, v1);
	printf("�������¶����йصıߣ����������: ");
	scanf("%d", &n);
	for (k = 0; k < n; k++)
	{
		printf("��������һ�����ֵ: ");
		scanf("%s", v2);
		InsertArc(&g, v1, v2);
	}
	Display(g);
	printf("������������Ľ��:\n");
	DFSTraverse(g, visit);
	printf("������������Ľ��:\n");
	BFSTraverse(g, visit);
	DestroyGraph(&g);

	rewind(stdin);
	getchar();
	return 0;
}