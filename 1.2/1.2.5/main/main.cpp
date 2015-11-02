/**
* Question: 在二元树中找出和为某一值的所有路径
* Author: imtian
* Date: 2015/9/25
* ------
* Thinking:
* Code Explain:
**/

#include <stdio.h>

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


int main()
{
    return 0;
}