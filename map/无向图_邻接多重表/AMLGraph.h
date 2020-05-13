/* ����ͼ���ڽӶ��ر�洢��ʾ */
#pragma once

#define MAX_NAME 3 /* �����ַ�������󳤶�+1 */
#define MAX_INFO 80 /* �����Ϣ�ַ�������󳤶�+1 */
typedef char InfoType;
typedef char VertexType[MAX_NAME]; /* �ַ������� */
#define MAX_VERTEX_NUM 20
typedef enum { unvisited, visited }VisitIf;
typedef struct EBox
{
	VisitIf mark; /* ���ʱ�� */
	int ivex, jvex; /* �ñ����������������λ�� */
	struct EBox *ilink, *jlink; /* �ֱ�ָ�������������������һ���� */
	InfoType *info; /* �ñ���Ϣָ�� */
}EBox;
typedef struct
{
	VertexType data;
	EBox *firstedge; /* ָ���һ�������ö���ı� */
}VexBox;
typedef struct
{
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum; /* ����ͼ�ĵ�ǰ�������ͱ��� */
}AMLGraph;
int LocateVex(AMLGraph G, VertexType u);
Status CreateGraph(AMLGraph *G);
VertexType* GetVex(AMLGraph G, int v);
Status PutVex(AMLGraph *G, VertexType v, VertexType value);
int FirstAdjVex(AMLGraph G, VertexType v);
int NextAdjVex(AMLGraph G, VertexType v, VertexType w);
Status InsertVex(AMLGraph *G, VertexType v);
Status DeleteArc(AMLGraph *G, VertexType v, VertexType w);
Status DeleteVex(AMLGraph *G, VertexType v);
void DestroyGraph(AMLGraph *G);
Status InsertArc(AMLGraph *G, VertexType v, VertexType w);
Boolean visite[MAX_VERTEX_NUM]; /* ���ʱ�־����(ȫ����) */
Status(*VisitFunc)(VertexType v);
void DFS(AMLGraph G, int v);
void DFSTraverse(AMLGraph G, Status(*visit)(VertexType));
void BFSTraverse(AMLGraph G, Status(*Visit)(VertexType));
void MarkUnvizited(AMLGraph G);
void Display(AMLGraph G);
