#include "head.h"
Status visit(VertexType v)
{
	printf("%s ", v);
	return OK;
}

int main()
{
	int j, k, n;
	OLGraph g;
	VertexType v1, v2;
	CreateDG(&g);
	Display(g);
	printf("修改顶点的值，请输入原值 新值: ");
	scanf("%s%s", v1, v2);
	PutVex(&g, v1, v2);
	printf("插入新顶点，请输入顶点的值: ");
	scanf("%s", v1);
	InsertVex(&g, v1);
	printf("插入与新顶点有关的弧，请输入弧数: ");
	scanf("%d", &n);
	for (k = 0; k < n; k++)
	{
		printf("请输入另一顶点的值 另一顶点的方向(0:弧头 1:弧尾): ");
		scanf("%s%d", v2, &j);
		if (j)
			InsertArc(&g, v2, v1);
		else
			InsertArc(&g, v1, v2);
	}
	Display(g);
	printf("删除一条弧，请输入待删除弧的弧尾 弧头：");
	scanf("%s%s", v1, v2);
	DeleteArc(&g, v1, v2);
	Display(g);
	printf("删除顶点及相关的弧，请输入顶点的值: ");
	scanf("%s", v1);
	DeleteVex(&g, v1);
	Display(g);
	printf("深度优先搜索的结果:\n");
	DFSTraverse(g, visit);
	printf("广度优先搜索的结果:\n");
	BFSTraverse(g, visit);
	DestroyGraph(&g);
	

	rewind(stdin);
	getchar();
	return 0;
}