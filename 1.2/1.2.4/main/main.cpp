/**
* Question: �������������
* Author: imtian
* Date: 2015/9/24
* ------
* Thinking: ��Ϊ��O(N)�ĸ��Ӷȣ��������õ�DP��˼�롣
*   ��¼�µ�ǰԪ��֮�ͣ�Ϊ������״̬������󣩣�������
*   Ŀǰ���õ����ͱȽϣ�����������£����������״̬
*   ���ۼ���ѭ������̣������ǰ��С��0���������״̬��
*   ������㡣
* Code Explain: 
**/

#include <stdio.h>

int max_subarray_sum(int *arr, unsigned int n)
{
	int cur_sum = 0;
	int max_sum = 0;

	for(unsigned int i = 0; i < n; i++)
	{
		cur_sum += arr[i];
		
		if(cur_sum < 0)
			cur_sum = 0;
		
		if(cur_sum > max_sum)
			max_sum = cur_sum;
	}

	if(max_sum == 0)    //�������ȫΪ��������ʱmax_sum = 0.
	{
		max_sum =  arr[0];
		for(i = 0; i < n; i++)
		{
			if(arr[i] > max_sum)
				max_sum = arr[i];
		}
	}

	return max_sum;
}

int main()
{
	int max_sum;
	int arr[] = {1, -2, 3, 10, -4, -7, 2, -5};
	
	max_sum = max_subarray_sum(arr, 8);

	printf("max sum is: %d\n", max_sum);

	return 0;
}