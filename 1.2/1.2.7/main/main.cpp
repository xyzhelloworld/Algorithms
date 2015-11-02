/**
* Question: 翻转句子中单词的顺序
* Author: imtian
* Date: 2015/9/28
* ------
* Thinking: 先将整句话反转，之后在句子内部以空格为分隔符，将单词反转
* Code Explain:
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str, unsigned int start, unsigned int end)
{
	char tmp;
	unsigned int limit = start + (end-start)/2;

	while(start <= limit)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;

		start++;
		end--;
	}
}

void reverse_word(char *str)
{
	char *backup;
	unsigned int start = 0, limit;
	
	while(*str)
	{
		limit = 0;
		backup = str;

		while(*str != ' ' && *str)
		{
			limit++;
			str++;
		}

		if(*str == ' ')    //防止str指针跳过'\0'而修改字符串后面的数据，造成程序运行错误
			str += 1;

		reverse(backup, start, limit-1);
	}
}


int main()
{
	char str[] = "I am a student.";

	reverse(str, 0, strlen(str)-1);
	reverse_word(str);

	printf("%s\n", str);

	return 0;
}