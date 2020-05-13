#pragma once
typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree; /* 动态分配数组存储赫夫曼树 */
typedef char **HuffmanCode; /* 动态分配数组存储赫夫曼编码表 */
int min1(HuffmanTree t, int i);
void select(HuffmanTree t, int i, int *s1, int *s2);
void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n);
