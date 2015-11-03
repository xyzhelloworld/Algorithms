/**
* Question: ����ջ�����ݽṹ��Ҫ�����һ��min�������ܹ��õ�ջ����СԪ�ء�
*   Ҫ����min��push�Լ�pop��ʱ�临�Ӷȶ���O(1)
* Author: imtian
* Date: 2015/9/23
* ------
* Thinking: �����Ѷ����ڣ�����ÿ�β���ֻ���浱ǰ��СԪ�ص�ֵ����Ϊһ��
*   ��СԪ�س�ջ�������޷���֪��СԪ�ص�ֵΪ���٣�������ÿ�ν�ջ����ʱ��
*   �жϽ�ջԪ���Ƿ�Ϊ��СԪ�أ������򱣴档���˿��Ա�����СԪ����ֵ��
*   ���ǻ����Խ�Ԫ�ص�λ�ñ��棬�ڱ������ֵԪ��ʱ��������Ȼ���Խ�ʡ��
*   ��ռ䣨��ͨ��������˵��һ��ջ����ֻ����һ�ֻ������͵�Ԫ�أ���
*   Ϊ�˼�ס��СԪ�أ�������Ҫһ�����б�����СԪ�أ�ÿ��������С��Ԫ��
*   ʱ����Ԫ�ز��������󼴿ɡ������ǲ���ʾ����
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

	if(m_minIndex.size() == 0)    //������Сֵջ
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