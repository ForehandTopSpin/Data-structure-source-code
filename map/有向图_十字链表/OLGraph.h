/* 有向图的十字链表存储表示 */
#pragma once

typedef char InfoType;
#define MAX_Info 80 /* 信息字符串最大长度+1 */
#define MAX_VERTEX_NAME 3  /* 顶点字符串最大长度+1 */
typedef char  VertexType[MAX_VERTEX_NAME];
#define MAX_VERTEX_NUM 20
typedef struct ArcBox
{
	int tailvex, headvex; /* 该弧的尾和头顶点的位置 */
	struct ArcBox *hlink, *tlink; /* 分别为弧头相同和弧尾相同的弧的链域 */
	InfoType *info; /* 该弧相关信息的指针(可无) */
}ArcBox; /* 弧结点 */
typedef struct
{
	VertexType data;
	ArcBox *firstin, *firstout; /* 分别指向该顶点第一条入弧和出弧 */
}VexNode; /* 顶点结点 */
typedef struct
{
	VexNode xlist[MAX_VERTEX_NUM]; /* 表头向量(数组) */
	int vexnum, arcnum; /* 有向图的当前顶点数和弧数 */
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
Boolean visited[MAX_VERTEX_NUM]; /* 访问标志数组 */
Status(*VisitFunc)(VertexType); /* 函数变量 */
void DFS(OLGraph G, int i); /* DFSTraverse()调用 */
void DFSTraverse(OLGraph G, Status(*Visit)(VertexType));
void BFSTraverse(OLGraph G, Status(*Visit)(VertexType));
void Display(OLGraph G);
