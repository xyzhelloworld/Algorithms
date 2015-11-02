/**
* Question: 求子数组的最大和
* Author: imtian
* Date: 2015/9/24
* ------
* Thinking: 因为是O(N)的复杂度，因此需采用的DP的思想。
*   记录下当前元素之和（为其最优状态，既最大），将其与
*   目前所得的最大和比较，若大于则更新，否则继续。状态
*   的累加遵循这个过程：如果当前和小于0，则放弃该状态，
*   将其归零。
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

	if(max_sum == 0)    //如果数组全为负数，此时max_sum = 0.
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