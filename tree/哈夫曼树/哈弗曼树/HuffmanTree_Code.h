#pragma once
typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree; /* ��̬��������洢�շ����� */
typedef char **HuffmanCode; /* ��̬��������洢�շ�������� */
int min1(HuffmanTree t, int i);
void select(HuffmanTree t, int i, int *s1, int *s2);
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n);
