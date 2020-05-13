/* ����ͼ��ʮ������洢��ʾ */
#pragma once

typedef char InfoType;
#define MAX_Info 80 /* ��Ϣ�ַ�����󳤶�+1 */
#define MAX_VERTEX_NAME 3  /* �����ַ�����󳤶�+1 */
typedef char  VertexType[MAX_VERTEX_NAME];
#define MAX_VERTEX_NUM 20
typedef struct ArcBox
{
	int tailvex, headvex; /* �û���β��ͷ�����λ�� */
	struct ArcBox *hlink, *tlink; /* �ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ������� */
	InfoType *info; /* �û������Ϣ��ָ��(����) */
}ArcBox; /* ����� */
typedef struct
{
	VertexType data;
	ArcBox *firstin, *firstout; /* �ֱ�ָ��ö����һ���뻡�ͳ��� */
}VexNode; /* ������ */
typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM]; /* ��ͷ����(����) */
	int vexnum, arcnum; /* ����ͼ�ĵ�ǰ�������ͻ��� */
}OLGraph;
int LocateVex(OLGraph G, VertexType u);
Status CreateDG(OLGraph *G);
void DestroyGraph(OLGraph *G);
VertexType* GetVex(OLGraph G, int v);
Status PutVex(OLGraph *G, VertexType v, VertexType value);
int FirstAdjVex(OLGraph G, VertexType v);
int NextAdjVex(OLGraph G, VertexType v, VertexType w);
void InsertVex(OLGraph *G, VertexType v);
Status DeleteVex(OLGraph *G, VertexType v);
Status InsertArc(OLGraph *G, VertexType v, VertexType w);
Status DeleteArc(OLGraph *G, VertexType v, VertexType w);
Boolean visited[MAX_VERTEX_NUM]; /* ���ʱ�־���� */
Status(*VisitFunc)(VertexType); /* �������� */
void DFS(OLGraph G, int i); /* DFSTraverse()���� */
void DFSTraverse(OLGraph G, Status(*Visit)(VertexType));
void BFSTraverse(OLGraph G, Status(*Visit)(VertexType));
void Display(OLGraph G);
