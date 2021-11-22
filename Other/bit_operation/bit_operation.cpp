#include <iostream>
#include <string>

using namespace std;


int add(int a, int b);
int addRecursion(int a, int b);
int _minus(int a, int b);
int multuply(int a, int b);
int divide(int a, int b);


int main()
{
    cout << add(10, 12) << endl;
    cout << addRecursion(10, 12) << endl;
    cout << _minus(12, 10) << endl;
    cout << multuply(10, 12) << endl;
    cout << divide(120, 10) << endl;
    return 0; 
}



// 非进位和a + 进位b，直到进位为0停止
int add(int a, int b)
{
    while (b != 0)      // 当进位为 0 时跳出
    {
        int c = a ^ b;      // c = 非进位和
        b = (a & b) << 1;   // b = 进位
        a = c;              // a = 非进位和
    }

    return a;
}

int addRecursion(int a, int b)
{
    if (b == 0) return a;
    return add(a ^ b, (a & b) << 1);
}

int _minus(int a, int b)
{
    return add(a, add(~b, 1));
}


/* 乘法（设计算法过程，粗劣版）
 * 思想：
     模拟10进制 a * b
     如果 b 最后一位为0
        sum = sum
     如果 b 最后一位为1
        sum += a
     b >> 1
     a << 1
     直到 b 为0停止
   模拟：
        1 1 0 1
    *   1 1 1 0
    -------------
        0 0 0 0
      1 1 0 1
    1 1 0 1
  1 1 0 1
------------------
1 0 1 1 0 1 1 0
 *
 */

int multuply(int a, int b)
{
    // 符号位，true为正
    bool sign = (a ^ b) > 0 ? true : false;
    a = abs(a);
    b = abs(b);

    int sum = 0;

    while (b != 0)
    {
        if ((b & 1) != 0)  // 最后一位为1，即奇数
            sum += a;
        b >>= 1;
        a <<= 1;
    }

    return sign ? sum : -sum;

}



/*
 * 除法 a / b 
 * 思想：
 *  用减法代替，不过
 *  b * 2^(i-1) <= a < b * 2^i
 *  a -= ( b * 2^(i-1) )
 *  直到 a 小于 b 为止
 * 模拟：
    a = 22, b = 3

     a - (b <<  k)
    ------------------
    22 -  3 << 31   < 0
    22 -  3 << 30   < 0
    ...
    22 -  3 <<  2   > 0     ---> (1 << 2)

    10 -  3 <<  1   > 0     ---> (1 << 1)

     4 -  3 <<  0   > 0     ---> (1 << 0)

     1 <  3                 ---> stop
 *
 */

int divide(int a, int b)
{

    // 符号位，正为true
    bool sign = (a ^ b) >= 0 ? true : false;

    // 使用无符号int可以容纳MIN取绝对值不越界
    unsigned int ua = abs(a);
    unsigned int ub = abs(b);
    unsigned int sum = 0;

    while (ua >= ub)
    {   
        for (int i = 31; i >= 0; i--)
        {
            // 左移b改成右移a的话，怎么着也不会越界
            // 右移的另外一个好处是不用每次都从边界处开始移动（`raw ua`右移i才满足条件，`ua-=`后要满足条件肯定右移位数不能超过i）
            if (ua >> i >= ub)
            {
                ua -= (ub << i);
                sum += (1 << i);
            }
        }
    }

    return sign ? sum : -sum;
}
