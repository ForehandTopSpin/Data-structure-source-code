#pragma once

/**********��������˳��洢��ʾ*******/
#define MAX_TREE_SIZE 100		//��������������� 

//������������ѡ����������TElemType����ѡ����Ӧ��Nil
#define CHAR 0
#if CHAR
	typedef char TElemType;
	//���ַ����Կո��Ϊ��
	//TElemType Nil = ' ';   // ����ֲ���������SqBitree.c��ʹ�ã�����ֲ��������ᵼ���ض���
#define Nil " "    // ����������ȫ�ֱ��������ڽ��Nil��main.obj�ж��������SqBiTree.obj SqQueue.obj���ض��������

#else
	typedef int TElemType;
	//��������0Ϊ�� 
	//TElemType Nil = 0;	// �ֲ���������SqBitree.c��ʹ�ã�����ֲ��������ᵼ���ض���
#define Nil 0		// ����������ȫ�ֱ��������ڽ��Nil��main.obj�ж��������SqBiTree.obj SqQueue.obj���ض��������
#endif

typedef TElemType SqBiTree[MAX_TREE_SIZE]; /* 0�ŵ�Ԫ�洢����� */
typedef struct {
	int level, order; /* ���Ĳ�,�������(��������������) */
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
