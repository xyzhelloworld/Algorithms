/**
* Question: ��������нڵ��������
* Author: imtian
* Date: 2015/9/30
* ------
* Thinking: �������ڵ�������������Ϊ�ǽڵ��ı�����
*   ͨ�������������Է������¼����ص㣺
      1. Ҷ�ӽڵ������Զ��������Ҷ�ӽڵ㵽���ڵ������Զ
	  2. Ҷ�ӽڵ���Զ����·���������ڵ㣬�����ڵ����ڲ�ͬ����
	  3. Ҷ�ӽڵ���Զ����·�����������ڵ㣬�����ڵ�����ͬһ�ڵ�

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
