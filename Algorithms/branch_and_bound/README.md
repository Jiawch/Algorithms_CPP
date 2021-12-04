### 分支限界（BFS）

#### 写在前面

BFS也是一个搜寻算法，亦有模版可循

```
BFS(节点/图，参数)
  if (空)  return;
  
  queue<T> q;   // 定义队列
  q.push();     // 先入队列
  while (!q.empty()) {
      出队列和访问
      if 满足条件
          入队列
  }
```

#### 树BFS

- [树的层序遍历](./tree_bfs.cpp)
- [树的高度](./tree_bfs.cpp)

#### 图BFS

#### 网格BFS
