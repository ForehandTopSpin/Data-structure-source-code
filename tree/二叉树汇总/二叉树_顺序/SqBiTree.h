#pragma once

/**********二叉树的顺序存储表示*******/
#define MAX_TREE_SIZE 100		//二叉树的最大结点数 

//利用条件编译选择数据类型TElemType，并选择相应的Nil
#define CHAR 0
#if CHAR
	typedef char TElemType;
	//设字符型以空格符为空
	//TElemType Nil = ' ';   // 定义局部变量，在SqBitree.c中使用，定义局部变量不会导致重定义
#define Nil " "    // ！！！定义全局变量，用于解决Nil在main.obj中定义后，又在SqBiTree.obj SqQueue.obj里重定义的问题

#else
	typedef int TElemType;
	//设整型以0为空 
	//TElemType Nil = 0;	// 局部变量，在SqBitree.c中使用，定义局部变量不会导致重定义
#define Nil 0		// ！！！定义全局变量，用于解决Nil在main.obj中定义后，又在SqBiTree.obj SqQueue.obj里重定义的问题
#endif

typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0号单元存储根结点 */
typedef struct {
	int level, order; /* 结点的层,本层序号(按满二叉树计算) */
}position;
/***********************************************************************************/
Status InitBiTree(SqBiTree T);
void DestroyBiTree();
void ClearBiTree(SqBiTree T);
Status CreateBiTree(SqBiTree T);
Status BiTreeEmpty(SqBiTree T);
int BiTreeDepth(SqBiTree T);
Status Root(SqBiTree T, TElemType *e);
TElemType Value(SqBiTree T, position e);
Status Assign(SqBiTree T, position e, TElemType value);
TElemType Parent(SqBiTree T, TElemType e);
TElemType LeftChild(SqBiTree T, TElemType e);
TElemType RightChild(SqBiTree T, TElemType e);
TElemType LeftSibling(SqBiTree T, TElemType e);
TElemType RightSibling(SqBiTree T, TElemType e);
void Move(SqBiTree q, int j, SqBiTree T, int i);
Status InsertChild(SqBiTree T, TElemType p, Status LR, SqBiTree c);
Status DeleteChild(SqBiTree T, position p, int LR);
void PreTraverse(SqBiTree T, int e);
Status PreOrderTraverse(SqBiTree T, Status(*Visit)(TElemType));
void InTraverse(SqBiTree T, int e);
Status InOrderTraverse(SqBiTree T, Status(*Visit)(TElemType));
void PostTraverse(SqBiTree T, int e);
Status PostOrderTraverse(SqBiTree T, Status(*Visit)(TElemType));
void LevelOrderTraverse(SqBiTree T, Status(*Visit)(TElemType));
void Print(SqBiTree T);
