/**
* Question: ������С��K��Ԫ��-ʹ������
* Author: imtian
* Date: 2015/9/30
* ------
* Thinking: ���������ֽ��ⷽ����1. ���ö��������к����ݣ�֮���ȡ��С��k������
*   2. �����ڵ���Ϊk�Ķѣ�ͨ����ʣ��Ԫ�����root�ڵ�ԱȽ��жѵ�����
* Code Explain: heap_heap�����Ǵ󶥶ѵ�����������һ���ȶ�k���ڵ���жѵ�����
*   ֮��ʣ��Ԫ�����root�ڵ���жԱȡ�С�ڶ�root�ڵ㣬��root�ڵ��滻Ϊ��
*   �ڵ㣬Ȼ������ѡ�
**/

#include <stdio.h>


void heap_adjust(int arr[], int s, int n)
{
	int tmp;

	tmp = arr[s];

	/*
	�ѵ������ܽ��ҳ���Ľڵ��滻���ڵ�����ֹ�����ڵ�ÿ�α��滻��
	��Ҫ���µ����ѣ�Ҫ��֤�˶�����󶥶����ʡ������´ε��������
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