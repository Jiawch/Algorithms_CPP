### 1 堆的特性
 - 通常我们所讲的优先队列都是用堆来实现的
 - 一个大顶堆（小顶堆）既是大根树（小根树）也是完全二叉树
 - 在堆中执行插入和删除操作的时间复杂度都为O(logN)

### 2 堆的实现
 - [堆的抽象数据类型](./heap.h)
 - [大顶堆](./maxHeap.h)
 - [小顶堆](./minHeap.h)

### 3 C\+\+ STL的堆
 - [priority_queue](http://www.cplusplus.com/reference/queue/priority_queue/?kw=priority_queue)：基于向量来实现的大顶堆，可以自定义比较函数，因此也可以作为小顶堆。
 ```
 #include <queue>
 priority_queue<int, vector<int>, greater<int> > minHeap;
 priority_queue<int, vector<int>, less<int> > maxHeap;
 
 // push, top, pop; 注意，这里和stack一样调用，而不是和queue一样
 
 // 自定义1
 static bool cmp(int& a, int& b) {   // & 很重要，可以减少很多内存
     return a < b;
 }
 priority_queue<int, vector<int>, decltype(&cmp)> maxHeap(cmp);
 
 // 自定义2
 struct cmp {
    bool operator()(int a, int b) {
        return a < b;
    }
 };
 priority_queue<int, vector<int>, cmp> maxHeap;
 ```

### 4 堆的应用
 - [堆排序](../../Algorithms/sort/heapSort.h)
 - [机器调度](../../Algorithms/greedy_method/LPTSchedule.cpp)
 - 霍夫曼编码

#### 大顶堆例子
```
// 一
priority_queue<int, vector<int>, less<int>> maxHeap;

// 二
static bool cmp(int& a, int& b) {
    return a < b;
}
priority_queue<int, vector<int>, decltype(&cmp)> maxHeap(cmp);

// 三
auto cmp = [&](int& a, int& b) {
    return a < b;
};
priority_queue<int, vector<int>, decltype(cmp)> maxHeap(cmp);

// 四
static bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first || a.first == b.first && a.second > b.second;
}
```

### 堆排

- [例子](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/)
