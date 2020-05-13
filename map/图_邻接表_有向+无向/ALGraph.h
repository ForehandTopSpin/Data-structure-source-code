#pragma once
/*  图的邻接表存储表示 */
#define MAX_NAME 3 /* 顶点字符串的最大长度+1 */
typedef int InfoType; /* 存放网的权值 */
typedef char VertexType[MAX_NAME]; /* 字符串类型 */
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, AG, AN }GraphKind; /* {有向图,有向网,无向图,无向网} */
typedef struct ArcNode
{
	int adjvex; /* 该弧所指向的顶点的位置 */
	struct ArcNode *nextarc; /* 指向下一条弧的指针 */
	InfoType *info; /* 网的权值指针） */
}ArcNode; /* 表结点 */
typedef struct
{
	VertexType data; /* 顶点信息 */
	ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
}VNode, AdjList[MAX_VERTEX_NUM]; /* 头结点 */
typedef struct
{
	AdjList vertices;
	int vexnum, arcnum; /* 图的当前顶点数和弧数 */
	int kind; /* 图的种类标志 */
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
Boolean visited[MAX_VERTEX_NUM]; /* 访问标志数组(全局量) */
void(*VisitFunc)(char* v); /* 函数变量(全局量) */
void DFS(ALGraph G, int v);
void DFSTraverse(ALGraph G, void(*Visit)(char*));
void BFSTraverse(ALGraph G, void(*Visit)(char*));
void Display(ALGraph G);