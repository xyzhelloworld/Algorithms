/*
定义 Fibonacci 数列如下:
      / 0             n=0
f(n)= | 1             n=1
      \ f(n-1)+f(n-2) n=2
输入 n,用最快的方法求该数列的第 n 项。

这里没有采用递归调用，利用空间换时间的思路，可将时间复杂度控制在O(N),
当然网上有人用数学归纳法将复杂度控制在O(logN)，这个后面再去考虑。
使用递归算法计算fibonacci的第n项的值会重复计算一些项，比如计算完
f(n-1)后，程序将再次计算f(n-2)，实际上f(n-2)及之前的项已经计算过
一次了，这里再次计算就重复了。当n非常大时，这样是很不好的。
这里我们使用空间换时间的思路，定义一个大小为2的数组，用于存放f(n-1)和
f(n-2)的值。初始值为arr[2] = {1, 0}，每次计算完后，更新arr即可。
    result = arr[0] + arr[1];
    arr[1] = arr[0];
    arr[0] = result;
*/


#include <iostream>

using namespace std;

unsigned int loop_fibonacci(int n)
{
    unsigned int arr[2] = {1, 0};    // arr[2] = {f(n-1), f(n02)}  n>=2
    unsigned int result;

    if(n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        for(int i=1; i < n; i++)    //这里计算f(2) ~ f(n), 所以只需要循环n-1次即可。
        {
            result = arr[0] + arr[1];
            arr[1] = arr[0];
            arr[0] = result;
        }
    }

    return result;
}


int main()
{
    cout << loop_fibonacci(10) << endl;
    return 0;
}
