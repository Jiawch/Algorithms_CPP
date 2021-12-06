// 图BFS
struct Graph {
    vector<int> vexs;   // 顶点
    vector<vector<int>> adj_matrix; // 边，邻接矩阵表示
};

vector<bool> visited(MAX);  // 默认为0，即为false
void BFS(Graph g) {
    queue<int> q;
    // 若是联通图，只会执行一次
    for (int i = 0; i < g.vexs.size(); i++) {
        if (visited[i] == false) {
            q.push(g.vexs[i]);
            while (!q.empty()) {
                int j = q.front();
                q.pop();
                if (g.adj_matrix[i][j] == 1 && visited[j] == false) {
                    q.push(j);
                }
            }
        }
    }
}
