### 经典问题

#### [滑动窗口问题](./sliding_window.cpp)
- 和大于等于 target 的最短子数组
- 找到字符串中所有字母异位词
- 最小覆盖子串
- 无重复字符的最长子串

#### [环形链表](./cycle_list.cpp)
- 判断是否有环
- 寻找环入口
- 求环长度

#### [反转链表](./reverse_list.cpp)
- 维护三个指针

#### [树的对称性递归](./symmetry_recursion.cpp)
- 100 相同的树
- 226 翻转二叉树
- 104 二叉树的最大深度
- 110 平衡二叉树
- 543 二叉树的直径
- 617 合并二叉树
- 572 另一个树的子树
- 965 单值二叉树
- 101 对称二叉树
- 剑指 Offer 26 树的子结构

#### [背包问题]
- [特征](https://leetcode-cn.com/problems/word-break/solution/yi-tao-kuang-jia-jie-jue-bei-bao-wen-ti-kchg9/)
- [模版](https://leetcode-cn.com/problems/coin-change/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-sq9n/)
- [v2](https://leetcode.cn/problems/combination-sum-iv/solution/xi-wang-yong-yi-chong-gui-lu-gao-ding-bei-bao-wen-/)
> 0-1, 完全
> 最值，存在，组合
> 理论上共6种，完全背包的组合问题可能需要考虑顺序，所以是7种

#### [股票问题]
- [股票问题系列通解](https://leetcode-cn.com/circle/article/qiAgHn/)
- [一种解法团灭买卖股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/mai-mai-gu-piao-wen-ti-by-chen-wei-f-xvs1/)

#### [排列 / 组合 / 子集 问题](https://leetcode.cn/link/?target=https%3A%2F%2Flfool.github.io%2FLFool-Notes%2Falgorithm%2F排列-组合-子集问题.html)

#### [秒杀所有岛屿题目](https://leetcode.cn/link/?target=https%3A%2F%2Flfool.github.io%2FLFool-Notes%2Falgorithm%2F秒杀所有岛屿题目(DFS).html)

#### [蓄水池抽样](https://leetcode.cn/problems/random-pick-index/solution/zhong-gui-zhong-ju-xu-shui-chi-chou-yang-random-re/)
- Q：总的样本数量未知，从所有样本中抽取若干个，要求每个样本被抽到的概率相等。
- A：假设当前正要读取第n个数据，则我们以1/n的概率留下该数据，否则以(n-1)/n 的概率留下前n-1个数据中的一个。而前n-1个数组留下的那个概率为1/(n-1), 因此最终留下上次n-1个数中留下的那个数的概率为[1/(n-1)]\*[(n-1)/n] = 1/n,符合均匀分布的要求。

#### [二叉树路径](https://leetcode.cn/problems/path-sum-ii/solution/yi-pian-wen-zhang-jie-jue-suo-you-er-cha-oo63/)
- 对于边的遍历（每个DFS前后都有选择与撤销）
- 对于点点遍历（只在最前和最后的DFS进行选择和撤销）

#### [单调栈](https://programmercarl.com/0739.每日温度.html)

#### [二分](https://leetcode.cn/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/)
- lower_bound: 第一个 >= target 的指针
- upper_bound：第一个 > target 的指针

#### [二叉树的中序后继](https://learnku.com/articles/40918)
