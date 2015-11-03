/**
* Question: 定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
*   要求函数min、push以及pop的时间复杂度都是O(1)
* Author: imtian
* Date: 2015/9/23
* ------
* Thinking: 此题难度在于，我们每次不能只保存当前最小元素的值。因为一旦
*   最小元素出栈，我们无法得知次小元素的值为多少，所以在每次进栈操作时，
*   判断进栈元素是否为最小元素，若是则保存。除了可以保存最小元素数值，
*   我们还可以将元素的位置保存，在保存非数值元素时，这样显然可以节省许
*   多空间（从通用性上来说，一个栈不能只保存一种或几种类型的元素）。
*   为了记住最小元素，我们需要一个队列保存最小元素，每次遇到更小的元素
*   时，将元素插入队列最后即可。下面是测试示例：
*     data stack:
*     92     64     17     22     10     11     16     30     60     37

*     index of mininum element:
*     0      1      2      2      4      4      4      4      4       4
*
* Code Explain: 
* 
**/

#include <iostream>
#include <cstddef>
#include <deque>
#include <assert.h>
#include <stdlib.h>
#include <time.h> 

using namespace std;

template <typename T>
class CStackWithMin
{
	public:
		CStackWithMin(void){}
		virtual ~CStackWithMin(void){}
		
		const T& top(void) const; 
		void push(const T& value); 
		void pop(void); 
		const T& min(void) const;
		const void print_stack();
		
	private:
		deque<T> m_data;
		deque<T> m_minIndex;
};

template <typename T> 
const T& CStackWithMin<T>::top() const 
{ 
	return m_data.back(); 
}

template <typename T> 
void CStackWithMin<T>::push(const T& value) 
{
	m_data.push_back(value);

	if(m_minIndex.size() == 0)    //更新最小值栈
		m_minIndex.push_back(0); 
	else 
	{ 
		if(value < m_data[m_minIndex.back()]) 
			m_minIndex.push_back(m_data.size() - 1);
		else 
			m_minIndex.push_back(m_minIndex.back()); 
	} 
}

template <typename T> 
void CStackWithMin<T>::pop() 
{ 
	m_data.pop_back(); 
	m_minIndex.pop_back();
}

template <typename T>
const T& CStackWithMin<T>::min() const 
{ 
	assert(m_data.size() > 0); 
	assert(m_minIndex.size() > 0); 

	return m_data[m_minIndex.back()]; 
}

template <typename T>
const void CStackWithMin<T>::print_stack()
{
	cout<< "data stack:"<< endl;

	for(int i=0; i < m_data.size(); i++)
		cout<< m_data.at(i)<< "\t";

	cout<< endl;

	cout<< "index of mininum element:"<< endl;

	for(i=0; i < m_minIndex.size(); i++)
		cout<< m_minIndex.at(i)<< "\t";

	cout<< endl;
}


int main()
{
	CStackWithMin<int> *min_stack = new CStackWithMin<int>();

	srand(unsigned(time(0)));

	for(int i=0; i < 10; i++)
		min_stack->push(rand() % 100);

	min_stack->print_stack();

	return 0;
}