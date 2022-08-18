### String 类型常见操作

```
// 声明定义
string s1 = "";

// 长度
s1.size();

// 获取下标字符
s1[i];

// 截取
s1.substr(pos, n);

// 替换（同时改变原来的值）
s1.replace(pos, n, s2);

// 查找（找不到返回s.npos）
s1.find(s2)  // 查找s1是否包含s2，找到则返回索引（索引必<s1.size())
如果要判断找不到，可以用 `s1.find(s2) >= s1.size()` 等价于 `s1.find(s1) == string::npos`

// 比较（相等时返回0；s1>s2时返回1，s1<s2时返回-1）
if (s1 < s2) {}

// 排序（不返回）
sort(s1.begin(), s1.end(), cmp);

// 反转（不返回）
reverse(s1.begin(), s1.end());

// 读取
#include <sstream>
stringstream ss(str);
string s;
while (ss >> s)    do sth.

// 实现 python 的 split 操作
stringstream ss(s);
string sub_s;
while (getline(ss, sub_s, '_')) do sth.
```

