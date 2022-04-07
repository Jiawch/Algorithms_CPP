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
 
 // 自定义
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

### 5 大顶堆例子
```
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main () {
    vector<int> a = {50, 45, 40, 20, 25, 35, 30, 10, 15};
    stable_sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';            // 50 45 40 35 30 25 20 15 10 
    }
    cout << endl;

    vector<int> b = {50, 45, 40, 20, 25, 35, 30, 10, 15};
    priority_queue<int, vector<int>, less<int> > maxHeap;
    for (int i = 0; i < b.size(); i++) {
        maxHeap.push(b[i]);
    }
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << ' ';   // 50 45 40 35 30 25 20 15 10 
        maxHeap.pop();
    }
    cout << endl;

    return 0;
}
```

一个是静态函数，一个是类
```
static bool cmp(int a, int b) {
    return a < b;
}
sort(arr.begin(), arr.end(), cmp)

class cmp {
    bool operator()(int a, int b) {
        return a < b;
    }
};
priority_queue<int, vector<int>, cmp> maxHeap;
```

### 堆排

- [例子](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/)
