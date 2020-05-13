#pragma once
/*  �������Ķ�������洢��ʾ */
/*  �����������룬ѡ����������*/
//todo:������������
#define CHAR	 // int��char��ѡһ

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
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
}BiTNode, *BiTree;

Status InitBiTree(BiTree *T);
void DestroyBiTree(BiTree *T);
void ClearBiTree(BiTree *T);	 // ʵ��Ч����DestroyBiTreeһ��
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
Status InsertChild(BiTree p, int LR, BiTree c); /* �β�T���� */
Status DeleteChild(BiTree p, int LR); /* �β�T���� */
void PreOrderTraverse(BiTree T, Status(*Visit)(TElemType));
void InOrderTraverse(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse1(BiTree T, Status(*Visit)(TElemType));
Status InOrderTraverse2(BiTree T, Status(*Visit)(TElemType));
void PostOrderTraverse(BiTree T, Status(*Visit)(TElemType));
void LevelOrderTraverse(BiTree T, Status(*Visit)(TElemType));
