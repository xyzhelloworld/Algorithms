/**
* Question: 判断整数序列是不是二元查找树的后序遍历结果
* Author: imtian
* Date: 2015/9/29
* ------
* Thinking: 二叉查找树后续遍历序列，尾节点是root，序列中小于root的为左子树，
*   大于root的为右子树。通过递归判断左右子树是否满足后续遍历结果即可得出此
*   序列是否为某二叉查找树的后续遍历结果。
* Code Explain: 递归调用verify_bst判断所有子树后续遍历序列是否满足后续遍历
*   结果，先在序列中找出第一个大于root的元素，之后测试后续元素是否有小于root
*   的元素，若有则返回FALSE。
**/

#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

 
BOOL vertify_bst(int arr[], int length)
{
	int root;
	BOOL left = TRUE, right = TRUE;

	root = arr[length-1];

	for(int i=0; i < length-1; i++)
		if(arr[i] > root)
			break;

	for(; i < length-1; i++)
		if(arr[i] < root)
			return FALSE;

	if(i > 0)
		left = vertify_bst(arr, i);

	if(i < length-1)
		right = vertify_bst(arr+i, length-i-1);

	return (left && right);
}


int main()
{
	BOOL is_bst;
	int arr[] = {5, 7, 6, 9, 11, 10, 8};
	
	is_bst = vertify_bst(arr, 7);

	if(is_bst)
		printf("The squence is the bst of a binary tree.\n");
	else
		printf("The squence isn't the bst of a binary tree.\n");

    return 0;
}