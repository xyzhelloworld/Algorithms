/**
* Question: 输入一颗二元树，从上往下按层打印树的每个结点，
*   同一层中按照从左往右的顺序打印
* Author: imtian
* Date: 2015/11/1
* ------
* Thinking:
* Code Explain:
**/

#include <iostream>
#include <stdlib.h>
#include <queue>

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

    cout<< "Input node data:"<< endl;
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

void visite_by_level(pbinary_tree_node node)
{
	if(node)
	{
		queue<pbinary_tree_node> level;
		level.push(node);

		cout<< endl<< "Visited by horizon direction:"<< endl;

		while(!level.empty())
		{
			node = level.front();
			level.pop();
			cout<< node->data<< "\t";

			if(node->left_child)
				level.push(node->left_child);

			if(node->right_child)
				level.push(node->right_child);
		}

		cout<< endl<< endl;
	}
}


int main()
{
	pbinary_tree_node root;

	root = create_binary_tree();
	visite_by_level(root);

    return 0;
}