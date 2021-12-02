### C++ 语法

 #### ASCII码
 ```
 char c = 'a';  // 97
 char c = 'A';  // 65
 char c = '0';  // 48
 ```

 #### map 中的 count 和 find
 ```
 count: 返回的是被查找元素的个数。注意，map中不存在相同元素，所以返回值只能是1或0。
 find: 返回的是被查找元素的位置，没有则返回map.end()
 ```
 
 #### vector 的 resize
 ```
 vector<vector<int>> matrix;
 matrix.resize(m, vector<int>(n)); // 分配一个m*n的初始空间，初始值为0
 ```
 
 #### 大小写转化
 ```
 tolower(char);
 toupper(char);
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

 #### 去重排序
 `unique`函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素，注意  
 (1) 这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址。   
 (2) unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，需要先进行排序，可以调用std::sort()函数
 ```
 sort(a.begin(), a.end());
 a.erase(unique(a.begin(), a.end()), a.end());
 ```
