#pragma once
/*  ͼ������(�ڽӾ���)�洢��ʾ */
//#define INFINITY INT_MAX /* ���������ֵ����� */    //  math.h���Ѿ�����infinity�� �˴����ͻ
#define MAX_VERTEX_NUM 20 /* ��󶥵���� */

#define MAX_NAME 5 /* �����ַ�������󳤶�+1 */
#define MAX_INFO 20 /* �����Ϣ�ַ�������󳤶�+1 */
typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];
typedef enum { DG, DN, AG, AN }GraphKind; /* {����ͼ,������,����ͼ,������} */
typedef struct
{
	VRType adj; /* �����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ� */
			/* �Դ�Ȩͼ��c��ΪȨֵ���� */
	InfoType *info; /* �û������Ϣ��ָ��(����) */
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM]; /* �������� */
	AdjMatrix arcs; /* �ڽӾ��� */
	int vexnum, arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
	GraphKind kind; /* ͼ�������־ */
}MGraph;

int LocateVex(MGraph G, VertexType u);
Status CreateFAG(MGraph *G);							// ��ȡ�ļ���Ϣ����������ͼ
Status CreateDG(MGraph *G);
Status CreateDN(MGraph *G);
Status CreateAG(MGraph *G);								// ��������ͼ
Status CreateAN(MGraph *G);
Status CreateGraph(MGraph *G);
void DestroyGraph(MGraph *G);
VertexType* GetVex(MGraph G, int v);
Status PutVex(MGraph *G, VertexType v, VertexType value);
int FirstAdjVex(MGraph G, VertexType v);
int NextAdjVex(MGraph G, VertexType v, VertexType w);
void InsertVex(MGraph *G, VertexType v);
Status DeleteVex(MGraph *G, VertexType v);
Status InsertArc(MGraph *G, VertexType v, VertexType w);
Status DeleteArc(MGraph *G, VertexType v, VertexType w);
Boolean visited[MAX_VERTEX_NUM];						/* ���ʱ�־����(ȫ����) */
Status(*VisitFunc)(VertexType);							/* �������� */
void DFS(MGraph G, int v);
void DFSTraverse(MGraph G, Status(*Visit)(VertexType));
void BFSTraverse(MGraph G, Status(*Visit)(VertexType));
void Display(MGraph G);


