/**
* Question: �Ѷ�Ԫ������ת��������˫������
* Author: imtian
* Date: 2015/9/23
* ------
* Thinking: ���������������ÿ����һ���ڵ㣬���ڵ�����˫������
* Code Explain: ���������һ���ڵ�ʱ�����˽ڵ��ַ����head_node, tail_node��
*   tail_nodeָ������β���������½ڵ�����롣head_nodeָ�������ײ������������
*   ��ӡ��������
**/

#include <stdio.h>
#include "function.h"

extern pbinary_tree_node head_node;
extern pbinary_tree_node tail_node;
extern void print_linklist1(pbinary_tree_node tail);

int main()
{
    pbinary_tree_node root;

    root = create_binary_tree();
	inorder_traversal(root);

	printf("\nlinklist: \n");
	printf("����: ");
	print_linklist(head_node);
	printf("����: ");
	print_linklist1(tail_node);

    return 0;
}