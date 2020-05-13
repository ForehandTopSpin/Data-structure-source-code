#pragma once
/*  ���Ķ�������(���ӣ��ֵ�)�洢��ʾ */
typedef char TElemType;
#define Nil ""    /* �Կո��Ϊ�� */
typedef struct CSNode
{
	TElemType data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
Status InitTree(CSTree *T);
void DestroyTree(CSTree *T);
Status CreateTree(CSTree *T);
Status TreeEmpty(CSTree T);
int TreeDepth(CSTree T);
TElemType Value(CSTree p);
TElemType Root(CSTree T);
CSTree Point(CSTree T, TElemType s);
Status Assign(CSTree *T, TElemType cur_e, TElemType value);
TElemType Parent(CSTree T, TElemType cur_e);
TElemType LeftChild(CSTree T, TElemType cur_e);
TElemType RightSibling(CSTree T, TElemType cur_e);
Status InsertChild(CSTree *T, CSTree p, int i, CSTree c);
Status DeleteChild(CSTree *T, CSTree p, int i);
void PreOrderTraverse(CSTree T, void(*Visit)(TElemType));
void PostOrderTraverse(CSTree T, void(*Visit)(TElemType));
void LevelOrderTraverse(CSTree T, void(*Visit)(TElemType));
