## 位操作

### 优先级

括号 > 成员访问 > 单元运算符 > 乘除 > 加减 > 移位 > 关系运算 > 位运算 > 逻辑运算 > 赋值

位运算（& > ^ > |）  
逻辑运算（&& > ||）

![](./operator_precedence.png)


### 二进制表示

正数：符号位为0，数值位为二进制源码表示   
负数：符号位为1，数值位为二进制补码表示（补码即为反码+1）  
（其中：0000 0000 为0，1000 0000为-256）

### 移位运算

- 左移：高位丢弃，低位补零（负数不能左移）
- 右移：无符号位，高位补零，低位丢弃；有符号位，高位补符号位，低位丢弃
- 总结：只考虑无符号的左右移，(unsigned int)x

### 常见的位运算

1. 乘除

```
int a = 2;
a >> 1; // ---> 1（右移1位相对除以2）
a << 1; // ---> 4（左移1位相当乘以2）
```

2. 相反数
```
int a = 2;
~a + 1; // ---> -2（取反加1相当于取相反数）
```

3. 取最值
```
const int MAX = ~(1 << (sizeof(int) * 8 - 1));  // 0111 1111 1111 1111, 1111 1111 1111 1111 
const int MIN = (1 << (sizeof(int) * 8 - 1));   // 1000 0000 0000 0000, 0000 0000 0000 0000
```

4. 乘除符号位
```
// 只考虑最高位，如果a,b异号，则异或后最高位为1；如果同号，则异或后最高位为0；
int a, b;
a ^ b >= 0; // ---> a, b 同号
a ^ b < 0; // ---> a, b 异号
```

5. 奇偶数
```
int a;
(a & 1) == 0; // ---> 偶数
(a & 1) != 0; // ---> 奇数
```

6. 消去最后一位1
```
int a = 0b1010;  // 10，0b开头表示二进制表示
a &= (a - 1);    // ---> 0b1000，消去最后一位1
```

7. 取最后一位1
```
int a = 0b1010;
a &= -a;    // --> 0b0010
```

8. 加减
```
// 加一
int n = 1;
n = -~n;
// 现在 n = 2

// 减一
int n = 2;
n = ~-n;
// 现在 n = 1
```



整数取反加1，正好变成其对应的负数(补码表示)；负数取反加一，则变为其原码，即正数

### 位转换

- [十进制转二进制](./bit_conversion.cpp) --> 倒除法，余数为0停止
- [二进制转十进制](./bit_conversion.cpp) --> 遍历，移位相加

### 位运算实现加减乘除

- [加法](./bit_operation.cpp) —— 非进位和+进位，进位为0停止
    - ![](https://pic.leetcode-cn.com/56d56524d8d2b1318f78e209fffe0e266f97631178f6bfd627db85fcd2503205-Picture1.png)

- [减法](./bit_operation.cpp) —— 取反加一
- [乘法](./bit_operation.cpp) —— 模拟十进制乘法
    - ![](https://upload-images.jianshu.io/upload_images/1925324-76fc13867d15d580.png?imageMogr2/auto-orient/strip|imageView2/2/w/448)
- [除法](./bit_operation.cpp) —— 模拟多次减法，但需优化

### 位转换 
