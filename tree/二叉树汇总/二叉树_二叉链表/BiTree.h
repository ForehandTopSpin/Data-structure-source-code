#pragma once
/*  二叉树的二叉链表存储表示 */
/*  利用条件编译，选择数据类型*/
//todo:整理条件编译
#define CHAR	 // int和char二选一

#ifdef CHAR 
typedef char TElemType;
#define Nil  ' '
#endif
#ifdef INT
typedef int TElemType;
#define Nil 0
#endif

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree;

Status InitBiTree(BiTree *T);
void DestroyBiTree(BiTree *T);
void ClearBiTree(BiTree *T);	 // 实际效果和DestroyBiTree一样
void CreateBiTree(BiTree *T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
TElemType Root(BiTree T);
TElemType Value(BiTree p);
void Assign(BiTree p, TElemType value);
TElemType Parent(BiTree T, TElemType e);
BiTree Point(BiTree T, TElemType s);
TElemType LeftChild(BiTree T, TElemType e);
TElemType RightChild(BiTree T, TElemType e);
TElemType LeftSibling(BiTree T, TElemType e);
TElemType RightSibling(BiTree T, TElemType e);
Status InsertChild(BiTree p, int LR, BiTree c); /* 形参T无用 */
Status DeleteChild(BiTree p, int LR); /* 形参T无用 */
void PreOrderTraverse(BiTree T, Status(*Visit)(TElemType));
void InOrderTraverse(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse1(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse2(BiTree T, Status(*Visit)(TElemType));
void PostOrderTraverse(BiTree T, Status(*Visit)(TElemType));
void LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType));
