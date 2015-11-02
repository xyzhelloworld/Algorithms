/**
* Question: 查找最小的K个元素-使用最大堆
* Author: imtian
* Date: 2015/9/30
* ------
* Thinking: 此题有两种解题方法，1. 先用堆排序排列好数据，之后截取最小的k个数。
*   2. 建立节点数为k的堆，通过将剩余元素与堆root节点对比进行堆调整。
* Code Explain: heap_heap函数是大顶堆调整函数，第一次先对k个节点进行堆调整。
*   之后将剩余元素与堆root节点进行对比。小于堆root节点，则将root节点替换为新
*   节点，然后调整堆。
**/

#include <stdio.h>


void heap_adjust(int arr[], int s, int n)
{
	int tmp;

	tmp = arr[s];

	/*
	堆调整不能仅找出大的节点替换父节点后就终止，父节点每次被替换下
	需要重新调整堆，要保证此堆满足大顶堆性质。否则下次调整会出错。
	*/
	for(int i=2*s; i <= n; i*=2)
	{                             
		if(i < n && arr[i] < arr[i+1])
			i++;

		if(tmp > arr[i])
			break;

		arr[s] = arr[i];
		s = i;
	}

	arr[s] = tmp;
}


int main()
{
	int k = 4, n=9;
	int arr[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};

	for(int i=k/2; i > 0; i--)
		heap_adjust(arr, i, k);
	
	printf("Max-Heap:\n");

	for(i=1; i <= k; i++)
		printf("%d\t", arr[i]);

	printf("\n\n");

	for(i=k+1; i < 9; i++)
	{
		if(arr[i] < arr[1])
		{
			arr[1] = arr[i];
			heap_adjust(arr, 1, k);
		}
	}

	printf("k min num:\n");
	
	for(i=1; i <= k; i++)
		printf("%d\t", arr[i]);

	printf("\n\n");
    
	return 0;
}