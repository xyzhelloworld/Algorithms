/**
* Question: 输入一颗二元查找树，将该树转换为它的镜像， 
*   即在转换后的二元查找树中，左子树的结点都大于右子树
*   的结点。 用递归和循环两种方法完成树的镜像转换。
* Author: imtian
* Date: 2015/11/1
* ------
* Thinking: 非递归代码要借助栈完成转换
* Code Explain:
**/

#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

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

void swap(pbinary_tree_node *node)
{
	pbinary_tree_node temp;
	
	temp = (*node)->left_child;
	(*node)->left_child = (*node)->right_child;
	(*node)->right_child = temp;
}

void recursion_transform(pbinary_tree_node *node)
{
	if(*node)
	{
		swap(node);
		recursion_transform(&(*node)->left_child);
		recursion_transform(&(*node)->right_child);
	}
}

void loop_transform(pbinary_tree_node *node)
{
	stack<pbinary_tree_node*> st;
	st.push(node);
	
	while(!st.empty())
	{
		node = st.top();
		st.pop();
		swap(node);
		
		if((*node)->left_child)
			st.push(&(*node)->left_child);

		if((*node)->right_child)
			st.push(&(*node)->right_child);
	}
}

void print_tree(pbinary_tree_node root)
{
	if(root)
	{
		print_tree(root->left_child);
		printf("%d\t", root->data);
		print_tree(root->right_child);
	}
}


int main()
{
	pbinary_tree_node root;

	root = create_binary_tree();

	printf("before:\n");
	print_tree(root);
	printf("\n");

	recursion_transform(&root);
	loop_transform(&root);

	printf("after:\n");
	print_tree(root);
	printf("\n");

    return 0;
}