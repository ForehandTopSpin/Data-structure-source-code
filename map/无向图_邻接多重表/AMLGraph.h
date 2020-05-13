/* 无向图的邻接多重表存储表示 */
#pragma once

#define MAX_NAME 3 /* 顶点字符串的最大长度+1 */
#define MAX_INFO 80 /* 相关信息字符串的最大长度+1 */
typedef char InfoType;
typedef char VertexType[MAX_NAME]; /* 字符串类型 */
#define MAX_VERTEX_NUM 20
typedef enum { unvisited, visited }VisitIf;
typedef struct EBox
{
	VisitIf mark; /* 访问标记 */
	int ivex, jvex; /* 该边依附的两个顶点的位置 */
	struct EBox *ilink, *jlink; /* 分别指向依附这两个顶点的下一条边 */
	InfoType *info; /* 该边信息指针 */
}EBox;
typedef struct
{
	VertexType data;
	EBox *firstedge; /* 指向第一条依附该顶点的边 */
}VexBox;
typedef struct
{
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum, edgenum; /* 无向图的当前顶点数和边数 */
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
Boolean visite[MAX_VERTEX_NUM]; /* 访问标志数组(全局量) */
Status(*VisitFunc)(VertexType v);
void DFS(AMLGraph G, int v);
void DFSTraverse(AMLGraph G, Status(*visit)(VertexType));
void BFSTraverse(AMLGraph G, Status(*Visit)(VertexType));
void MarkUnvizited(AMLGraph G);
void Display(AMLGraph G);
