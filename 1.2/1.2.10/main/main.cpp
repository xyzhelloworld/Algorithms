/**
* Question: 求二叉树中节点的最大距离
* Author: imtian
* Date: 2015/9/30
* ------
* Thinking: 二叉树节点间最大距离可以认为是节点间的边数，
*   通过画二叉树可以发现以下几个特点：
      1. 叶子节点相距最远，或者是叶子节点到根节点距离最远
	  2. 叶子节点最远距离路径经过根节点，两个节点属于不同子树
	  3. 叶子节点最远距离路径不经过根节点，两个节点属于同一节点

* Code Explain:
**/


#include <stdio.h>
#include <stdlib.h>


typedef struct btnode
{
    int data;
    struct btnode* left_child;
    struct btnode* right_child;
}binary_tree_node, *pbinary_tree_node;

pbinary_tree_node create_binary_tree()
{
    int data;
    pbinary_tree_node node = NULL;

    printf("Input node data:\n");
    scanf("%d", &data);
    fflush(stdin);

    if(data != -1){
        node = (pbinary_tree_node)malloc(sizeof(binary_tree_node));
        node->data = data;
        node->left_child = create_binary_tree();
        node->right_child = create_binary_tree();
    }

    return node;
}

void cal_max_distance()
{
}


int main()
{
    return 0;
}
