### 回溯（DFS）

#### 1. 写在前面

模版
```
DSF():
    if 递归结束条件:
        return;
    for 枚举:
        DFS() 
```

#### 2. 树DFS

- [树的先序/中序/后序/层次](./tree_dfs.cpp)

先序遍历：进入节点之前的操作 `-> ⭕️`  
后序遍历：离开节点之后的操作 `⭕️ ->`（**后序遍历的优点：后序遍历之后，可以对节点的数据、指针进行修改，因为节点已经访问过了** ）  

```
/* 遇到树DFS类似的题目，只需要思考如下模型：  */
 ⭕️     // 判断 base case ———— 当节点为null时，应该怎么做，不为null时，应该怎么做
/  \    // 访问相邻结点 ———— 然后递归的对其做左/右子树也做类似的处理
```

#### 3. 图DFS

- [数组全排列](./graph_dfs.cpp)
- [图遍历](./graph_dfs.cpp)

一般需要构造一个`vector<bool> visited(MAX)`数组表示被访问的状态

#### 4. 网格DFS


#### 5. reference

> [DFS](https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167208&idx=1&sn=d8118c7c0e0f57ea2bdd8aa4d6ac7ab7&chksm=88aa236ebfddaa78a6183cf6dcf88f82c5ff5efb7f5c55d6844d9104b307862869eb9032bd1f&token=1064083695&lang=zh_CN&scene=21#wechat_redirect)
> [BFS](https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167212&idx=1&sn=6af5ffe5b69075b21bb4743ddcee4e7c&chksm=88aa236abfddaa7cae70b42edb299d0a52d9f1cc4fc1fdba1116972fc0ca0275b8bfdf10851b&scene=178&cur_album_id=1338094723818668033#rd)

