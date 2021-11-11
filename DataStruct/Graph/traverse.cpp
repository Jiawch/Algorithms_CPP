#include <iostream>
#include <queue>
#define MAX 100
#define MAXVEX 100

using namespace std;


/* 邻接矩阵数据结构
 * 包含：
 *  1. 顶点数
 *  2. 边数
 *  3. 顶点表，一维数组表示
 *  4. 边表，二维数组表示
 */

struct MGraph {
    char vexs[MAXVEX];          // 顶点表
    int arc[MAXVEX][MAXVEX];    // 邻接矩阵，可看作边表
    int numVertexes;            // 顶点数
    int numEdges;               // 边数
};


/* 
 * !Date: 2021-10-26
 * （邻接矩阵的）深度优先遍历
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
 * （邻接矩阵的）广度优先遍历
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
                i = q.front();
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




/* 邻接表数据结构
 */

struct EdgeNode {       // 边表节点
    int adjvex;         // 邻接点域，存储该顶点对应下标
    int weight;         // 权重域
    EdgeNode *next;     // 键域，指向下一个邻接点
};

struct VertexNode {         // 顶点表节点
    int data;               // 顶点域
    EdgeNode *firstedge;    // 边表头指针
};

struct GraphList {
    VertexNode adjList[MAXVEX];
    int numVertexes;
    int numEdges;
};






/*! Author: Jiawch
 *! Date: 2021-11-11
 * 图的两种遍历v2
 */

struct Graph {
    vector<int> vexs;                   // 顶点表
    vector<vector<int> > adj_matrix;    // 边表，邻接矩阵
    vector<bool> visited;               // 访问标志
};



void DFS(Graph g)
{
    int num_ves = g.vexs.size();

    // 初始化图
    for (int i = 0; i < num_ves; i++)
    {
        g.visited[i] = false;
    }

    // 若是连通图，只会执行一次
    for (int i = 0; i < num_ves; i++)
    {
        if (g.visited[i] == false)
        {
            _DSF(g, i);
        }
    }
}

void _DFS(Graph &g, int i)
{
    visit(g.vexs[i]);
    g.visited[i] = true;

    for (int j = 0; j < g.vexs.size(); j++)
    {
        // 与i相临且未被访问的节点
        if (g.adj_matrix[i][j] == 1 && g.visited[j])
        {
            _DSF(g, j);
        }
    }
}



void BFS(Graph g)
{
    int num_ves = g.vexs.size();

    // 初始化图
    for (int i = 0; i < num_ves; i++)
    {
        g.visited[i] = false;
    }

    queue<int> q;
    // 若是连通图，只会进行一次
    for (int i = 0; i < num_ves; i++)
    {
        q.push(i);
        while (!q.empty())
        {
            i = q.front();
            q.pop();
            visit(g.vexs[i]);       // 出队列的时候访问
            g.visited[i] = false;

            for (int j = 0; j < num_ves; j++)
            {
                // 与i相邻且未被访问的节点
                if (g.adj_matrix[i][j] == 1 && g.visited[j] == false)
                {
                    q.push(j);
                }
            }
        }
    }

}



