/**
* Question: 左移递减数列查找某一个数
*   一个数组是由一个递减数列左移若干位形成的，比如{4，3，2，1，6，5} 
*  是由{6，5，4，3，2，1}左移两位形成
* Author: imtian
* Date: 2015/11/3
* ------
* Thinking: 任意切割左移后的递减数列，必然会得到一个递减子数列，和一个
*   非递减的子数列（此子数列也有可能会是递减数列，比如递减数列左移后和
*   原数列无异）。我们可以通过判断关键字是否在递减数列中
*     if(nums[start]) >= key && nums[end] <= key)
*   如不在此递减数列范围内，则重新切割非递减数列，直至找到关键字。
*
* Code Explain: 利用递归的二分查找可解决此题，以数列{4，3，2，1，6，5}
*   为例：
*      key = 6
*      start = 0
*      end = 5
*      mid = (start + end) / 2 = 2
*   此时nums[0 ~ mid]为递减数列，但是关键字不在其中，此时更新start的值：
*      start = mid + 1 = 3;
*      mid = (start + end) / 2 = 4
*   此时数列nums[3 ~ 5]为非递减数列，此时递减mid的值，直到nums[start ~ mid]
*   为递减数列为止，这里mid只需要递减一次即。这是再次检测关键字是否在递减
*   数列范围内，若不在，继续更新start的值，直到找到关键字位置或者返回-1为止。
**/

#include <stdio.h>


int rotate_search(int nums[], int start, int end, int key)
{
	int mid;

	if(nums == NULL || end < 0)
		return -1;

	if(start == end)
		if(nums[start] == key)
			return start;
	    else
			return -1;

	mid = (start + end)/2;

	if(nums[mid] == key)
		return mid;

	if(nums[mid] <= nums[start])    //判断nums[start ~ mid]数列是否为递减数列
	{
		if(nums[start] >= key && nums[mid] < key)
			return rotate_search(nums, start, mid - 1, key);
		else
			return rotate_search(nums, mid + 1, end, key);
	}
	else
	{
		if(nums[end] <= key && nums[mid] > key)    //判断nums[mid+1 ~ end]数列是否为递减数列
			return rotate_search(nums, mid + 1, end, key);
		else
			return rotate_search(nums, start, mid - 1, key);    //递减mid，直至nums[start ~ mid]为递减数列为止
	}
}


int main()
{
	int index = -1;
	int key = 5;
	int nums[6] = {4, 3, 2, 1, 6, 5};
    
	index = rotate_search(nums, 0, 5, key);

	printf("index of key in nums: %d\n", index);
	
	return 0;
}