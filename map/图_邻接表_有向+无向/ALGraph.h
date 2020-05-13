#pragma once
/*  ͼ���ڽӱ�洢��ʾ */
#define MAX_NAME 3 /* �����ַ�������󳤶�+1 */
typedef int InfoType; /* �������Ȩֵ */
typedef char VertexType[MAX_NAME]; /* �ַ������� */
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, AG, AN }GraphKind; /* {����ͼ,������,����ͼ,������} */
typedef struct ArcNode
{
	int adjvex; /* �û���ָ��Ķ����λ�� */
	struct ArcNode *nextarc; /* ָ����һ������ָ�� */
	InfoType *info; /* ����Ȩֵָ�룩 */
}ArcNode; /* ���� */
typedef struct
{
	VertexType data; /* ������Ϣ */
	ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
}VNode, AdjList[MAX_VERTEX_NUM]; /* ͷ��� */
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
	int kind; /* ͼ�������־ */
}ALGraph;
int LocateVex(ALGraph G, VertexType u);
Status CreateGraph(ALGraph *G);
void DestroyGraph(ALGraph *G);
VertexType* GetVex(ALGraph G, int v);
Status PutVex(ALGraph *G, VertexType v, VertexType value);
int FirstAdjVex(ALGraph G, VertexType v);
int NextAdjVex(ALGraph G, VertexType v, VertexType w);
void InsertVex(ALGraph *G, VertexType v);
Status DeleteVex(ALGraph *G, VertexType v);
Status InsertArc(ALGraph *G, VertexType v, VertexType w);
Status DeleteArc(ALGraph *G, VertexType v, VertexType w);
Boolean visited[MAX_VERTEX_NUM]; /* ���ʱ�־����(ȫ����) */
void(*VisitFunc)(char* v); /* ��������(ȫ����) */
void DFS(ALGraph G, int v);
void DFSTraverse(ALGraph G, void(*Visit)(char*));
void BFSTraverse(ALGraph G, void(*Visit)(char*));
void Display(ALGraph G);