#pragma once
/*  图的数组(邻接矩阵)存储表示 */
//#define INFINITY INT_MAX /* 用整型最大值代替∞ */    //  math.h里已经定义infinity， 此处会冲突
#define MAX_VERTEX_NUM 20 /* 最大顶点个数 */

#define MAX_NAME 5 /* 顶点字符串的最大长度+1 */
#define MAX_INFO 20 /* 相关信息字符串的最大长度+1 */
typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];
typedef enum { DG, DN, AG, AN }GraphKind; /* {有向图,有向网,无向图,无向网} */
typedef struct
{
	VRType adj; /* 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否； */
			/* 对带权图，c则为权值类型 */
	InfoType *info; /* 该弧相关信息的指针(可无) */
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM]; /* 顶点向量 */
	AdjMatrix arcs; /* 邻接矩阵 */
	int vexnum, arcnum; /* 图的当前顶点数和弧数 */
	GraphKind kind; /* 图的种类标志 */
}MGraph;

int LocateVex(MGraph G, VertexType u);
Status CreateFAG(MGraph *G);							// 读取文件信息，创建无向图
Status CreateDG(MGraph *G);
Status CreateDN(MGraph *G);
Status CreateAG(MGraph *G);								// 创建无向图
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
Boolean visited[MAX_VERTEX_NUM];						/* 访问标志数组(全局量) */
Status(*VisitFunc)(VertexType);							/* 函数变量 */
void DFS(MGraph G, int v);
void DFSTraverse(MGraph G, Status(*Visit)(VertexType));
void BFSTraverse(MGraph G, Status(*Visit)(VertexType));
void Display(MGraph G);


