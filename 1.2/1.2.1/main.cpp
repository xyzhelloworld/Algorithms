/**
* Question: 把二元查找树转变成排序的双向链表
* Author: imtian
* Date: 2015/9/23
* ------
* Thinking: 中序遍历二叉树，每遍历一个节点，将节点链入双向链表。
* Code Explain: 中序遍历第一个节点时，将此节点地址赋给head_node, tail_node。
*   tail_node指向链表尾部，辅助新节点的链入。head_node指向链表首部，这里仅用于
*   打印链表工作。
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
	printf("正序: ");
	print_linklist(head_node);
	printf("倒序: ");
	print_linklist1(tail_node);

    return 0;
}