/**
* Question: �ж����������ǲ��Ƕ�Ԫ�������ĺ���������
* Author: imtian
* Date: 2015/9/29
* ------
* Thinking: ��������������������У�β�ڵ���root��������С��root��Ϊ��������
*   ����root��Ϊ��������ͨ���ݹ��ж����������Ƿ������������������ɵó���
*   �����Ƿ�Ϊĳ����������ĺ������������
* Code Explain: �ݹ����verify_bst�ж����������������������Ƿ������������
*   ����������������ҳ���һ������root��Ԫ�أ�֮����Ժ���Ԫ���Ƿ���С��root
*   ��Ԫ�أ������򷵻�FALSE��
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