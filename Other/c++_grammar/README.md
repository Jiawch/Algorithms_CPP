### C++ 语法

 ### 头文件
 ```
 #include <iostream>
 #include <cstdio>
 #include <fstream>
 #include <algorithm>
 #include <cmath>
 #include <deque>
 #include <vector>
 #include <queue>
 #include <string>
 #include <cstring>
 #include <sstream>
 #include <map>
 #include <stack>
 #include <set>
 #include <utility>

 // 万能头文件，位于 /usr/local/include/bits
 #include <bits/stdc++.h>
 using namespace std;
 ```

 #### ASCII码
 ```
 char c = 'a';  // 97
 char c = 'A';  // 65
 char c = '0';  // 48
 ```
 
 #### vector 常用操作
 ```
 /* 二维数组初始化
  */
 vector<vector<int>> matrix;
 matrix.resize(m, vector<int>(n));   // 分配一个m*n的初始空间，初始值为0
 
 /* 查找
  */
 auto it = find(array.begin(), array.end(), target);  // 返回迭代器，太难记，就用auto直接替代
 auto i = distance(array.begin(), it);
 int i = distance(a.begin(), find(a.begin(), a.end(), target));
 
 /* 去重
  `unique`函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素，注意  
 (1) 这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址。   
 (2) unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，需要先进行排序，可以调用std::sort()函数
  */
 sort(array.begin(), array.end());
 array.erase(unique(array.begin(), array.end()), array.end());
 
 /* 赋值
  * /
 vector<int> a = {1,2,3,4};
 vector<int> b;
 a.assign(b.begin(), b.end());  // a = {1,2,3,4}
 a.assign(4, -1);               // a = {-1,-1,-1,-1}
 
 /* 插入 
  * /
 vector<int> a = {1,2,3}
 a.insert(a.begin(), 4);  // a = {4,1,2,3};
 ```

 #### map 常见操作
 ```
 /* 查找与计数
 count: 返回的是被查找元素的个数。注意，map中不存在相同元素，所以返回值只能是1或0。
 find: 返回的是被查找元素的位置，没有则返回map.end()
  */
 
 /* 遍历
  */
 for (auto [k, v] : map)
 
 /* 长度、大小
  */
 hash.size();
 
 /* 删除 key
  */
 hash.earse(key);
 ```
 
 #### string 常见操作
 ```
 /* 添加
  */
 str.push_back(char);
 str.append(string);
 
 /* 查找
  */
 str.find(subStr): 返回子串位置，没有则返回str.npos.
 
 /* 读取
  */
 istringstream ss(str);
 string s;
 while (ss >> s)  do sth.
 ```
 
 #### 七个字母数字相关的函数
 ```
islower(char c) 是否为小写字母
isupper(char c) 是否为大写字母
isdigit(char c) 是否为数字
isalpha(char c) 是否为字母
isalnum(char c) 是否为字母或者数字
toupper(char c) 字母小转大
tolower(char c) 字母大转小
 ```
 
 #### 编译、运行、调试
 ```
 g++ -g main.cpp -o main  // 编译
 ./main                   // 运行
 lldb ./main              // 调试
   b：设置断点
   r：开始调试
   n：执行下一行
   p：输出
 ```
 
 #### 类型转换
 ```
 to_string(int);  // int2string
 stoi(string);    // string2int
 ```
