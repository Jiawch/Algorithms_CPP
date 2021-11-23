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
s1.find(s2)

// 比较（相等时返回0；s1>s2时返回1，s1<s2时返回-1）
if (s1 < s2) {}

// 排序（不返回）
sort(s1.begin(), s1.end(), cmp);

// 反转（不返回）
reverse(s1.begin(), s1.end());

```
