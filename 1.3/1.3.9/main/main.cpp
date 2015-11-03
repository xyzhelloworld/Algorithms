/**
* Question: ���Ƶݼ����в���ĳһ����
*   һ����������һ���ݼ�������������λ�γɵģ�����{4��3��2��1��6��5} 
*  ����{6��5��4��3��2��1}������λ�γ�
* Author: imtian
* Date: 2015/11/3
* ------
* Thinking: �����и����ƺ�ĵݼ����У���Ȼ��õ�һ���ݼ������У���һ��
*   �ǵݼ��������У���������Ҳ�п��ܻ��ǵݼ����У�����ݼ��������ƺ��
*   ԭ�������죩�����ǿ���ͨ���жϹؼ����Ƿ��ڵݼ�������
*     if(nums[start]) >= key && nums[end] <= key)
*   �粻�ڴ˵ݼ����з�Χ�ڣ��������и�ǵݼ����У�ֱ���ҵ��ؼ��֡�
*
* Code Explain: ���õݹ�Ķ��ֲ��ҿɽ�����⣬������{4��3��2��1��6��5}
*   Ϊ����
*      key = 6
*      start = 0
*      end = 5
*      mid = (start + end) / 2 = 2
*   ��ʱnums[0 ~ mid]Ϊ�ݼ����У����ǹؼ��ֲ������У���ʱ����start��ֵ��
*      start = mid + 1 = 3;
*      mid = (start + end) / 2 = 4
*   ��ʱ����nums[3 ~ 5]Ϊ�ǵݼ����У���ʱ�ݼ�mid��ֵ��ֱ��nums[start ~ mid]
*   Ϊ�ݼ�����Ϊֹ������midֻ��Ҫ�ݼ�һ�μ��������ٴμ��ؼ����Ƿ��ڵݼ�
*   ���з�Χ�ڣ������ڣ���������start��ֵ��ֱ���ҵ��ؼ���λ�û��߷���-1Ϊֹ��
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

	if(nums[mid] <= nums[start])    //�ж�nums[start ~ mid]�����Ƿ�Ϊ�ݼ�����
	{
		if(nums[start] >= key && nums[mid] < key)
			return rotate_search(nums, start, mid - 1, key);
		else
			return rotate_search(nums, mid + 1, end, key);
	}
	else
	{
		if(nums[end] <= key && nums[mid] > key)    //�ж�nums[mid+1 ~ end]�����Ƿ�Ϊ�ݼ�����
			return rotate_search(nums, mid + 1, end, key);
		else
			return rotate_search(nums, start, mid - 1, key);    //�ݼ�mid��ֱ��nums[start ~ mid]Ϊ�ݼ�����Ϊֹ
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