/*
在一个字符串中找到第一个只出现一次的字符。如输入 abaccdeff,则输出 b

利用空间换时间的思想，ascii编码小于256,所以可以用字符的ascii作为下标，
用数组进行计数，然后扫描数组中等于1的下标，输出即可。
需要注意的是：一些标点符号以及数字的ascii的值小于字母，如果字符串中包含
标点符号，直接输出会出错。这里我们可以这样做，定义一个minIndex，每次扫描
数组中值为1的下标时，再去扫描字符串，找出该字符在字符串中的位置，如果小于
minIndex,则更新minIndex。此过程完成后，直接输出字符串中minIndex处的字符
即可
*/


#include <iostream>

using namespace std;


char find_once_char(char *str)
{
    unsigned int count[255] = {0};

    while(*str != '\0')
    {
        count[*str++] += 1;
    }

    int i;

    for(i=0; i < 255; i++)
    {
        if(count[i] == 1)
            break;
    }

    if(i == 255)
        return (char)0;    //0~31为ascii中非打印字符
    else
        return (char)i;
}


int main()
{
    char alphabet;
    alphabet = find_once_char("abbaccddeff");

    if(alphabet == '\0')
       cout<< "not find a suitable alphabet."<< endl;
    else
        cout << alphabet << endl;

    return 0;
}
