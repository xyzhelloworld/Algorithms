/**
* Question: 定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
*   要求函数min、push以及pop的时间复杂度都是O(1)
* Author: imtian
* Date: 2015/9/23
* ------
* Thinking:
* Code Explain: 
* 
**/

#include <iostream>
#include <cstddef>
#include <deque>
#include <assert.h>

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
		
	private:
		stack<T> m_data;
		stack<T> m_minIndex;
};

template <typename T> 
T& CStackWithMin<T>::top() 
{ 
	return m_data.back(); 
}

template <typename T> 
const T& CStackWithMin<T>::top() const 
{ 
	return m_data.back(); 
}

template <typename T> 
void CStackWithMin<T>::push(const T& value) 
{
	m_data.push_back(value);
	if(m_minIndex.size() == 0) 
		m_minIndex.push_back(0); 
	else 
	{ 
		if(value < m_data[m_minIndex.back()]) 
			m_minIndex.push_back(m_data.size() - 1);
		else 
			m_minIndex.push_back(m_minIndex.back()); 
	} 
}

template <typename T> void CStackWithMin<T>::pop() 
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


int main()
{
	return 0;
}