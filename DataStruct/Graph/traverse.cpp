#include <iostream>
#include <queue>
#define MAX 100

using namespace std;


/* 
 * !Date: 2021-10-26
 * 深度优先遍历
 * 思想：回溯
 */

// 访问标志的数组
bool visited[MAX];

void DFS (MGraph G, int i) {
    visited[i] = true;
    visit(G.vexs[i]);
    for (int j = 0; j < G.numVertexes; j++)
        if (G.arc[i][j] == 1 && !visited[j])    // 与i相连且未被访问的节点
            DFS (G, j);
}

void DFSTraverse (MGraph G) {
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = false;     // 初始化所有顶点状态都是未访问状态
    for (int i = 0; i < G.numVertexes; i++)
        if (!visited[i])        // 对未访问过的顶点调用DFS，若是连通图，只会执行一次
            DFS (G, i);
}



/*
 * !Date: 2021-10-26
 * 广度优先遍历
 * 思想：分支限界
 */

// 访问标志的数组
bool visited[MAX];

void BFSTraverse (MGraph G) {
    queue<int> q;
    for (int i = 0; i < G.numVertexes; i++)
        visited[i] = false;     // 初始化所有顶点状态都是未访问状态

    for (int i = 0; i < G.numVertexes; i++) {   //对每一个顶点做循环，若是连通图，只会进行一次
        if (!visited[i]) {
            visited[i] = true;
            visit(G.vexs[i]);       // 入队列即开始访问，也可出队列后访问
            q.push(i);
            while (!q.empty()) {    // 若当前队列不为空
                i = q.top();
                q.pop();
                for (int j = 0; j < G.numVertexes; j++) {
                    if (G.arc[i][j] == 1 && !visited[j]) {  // 与i相连且未被访问的节点
                        visited[j] = true;
                        visit(G.vexs[j]);
                        q.push(j);
                    }
                }
            }
        }
    }
}
