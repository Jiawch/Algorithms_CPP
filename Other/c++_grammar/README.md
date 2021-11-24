### C++ 语法

 #### ASCII码
 ```
 char c = 'a';  // 97
 char c = 'A';  // 65
 char c = '0';  // 48
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
