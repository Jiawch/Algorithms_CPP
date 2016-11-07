/*! Author��qwchen
 *! Date  : 2016-11-6
 * ��������ͼ��Ȩͼ��ǿ��ͨ������Kosaraju�㷨
 * ˼·��1.����һ��ͼG���ȼ������ķ���ͼ�����������
 *       2.��G�н��б�׼������������������ǰ��ողż���õ���˳����Ǳ�׼��˳������������Ϊ����ǵĽ��
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int num_v);
    void addEdge(int v, int w);
    void dfs(int v, bool marked[]);         // �������
    Graph getReverse();                     // ��ȡͼ�ķ���ͼ
    void getReversePost(Graph &G, int v, bool marked[], stack<int> &reverse_post_stack); // ��ȡͼ�����������
    void printStronglyConnectedComponent(); // ���ͼ��ǿ��ͨ��ͼ
private:
    int num_v_;        // ͼ�Ľ����
    vector<int> *adj_; // ͼ���ڽ�����
};

Graph::Graph(int num_v) {
    num_v_ = num_v;
    adj_ = new vector<int>[num_v];
}

void Graph::addEdge(int v, int w) {
    adj_[v].push_back(w);
}

void Graph::dfs(int v, bool marked[]) {
    marked[v] = true;
    cout << v << " ";
    for (auto w = adj_[v].begin(); w != adj_[v].end(); ++w) {
        if (!marked[*w]) {
            dfs(*w, marked);
        }
    }
}

Graph Graph::getReverse() {
    Graph reverse_G(num_v_);
    for (int v = 0; v < num_v_; v++) {
        for (auto w = adj_[v].begin(); w != adj_[v].end(); ++w) {
            reverse_G.adj_[*w].push_back(v);
        }
    }
    return reverse_G;
}

void Graph::getReversePost(Graph &G, int v, bool marked[], stack<int> &reverse_post_stack) {
    marked[v] = true;
    for (auto w = G.adj_[v].begin(); w != G.adj_[v].end(); ++w) {
        if (!marked[*w]) {
            getReversePost(G, *w, marked, reverse_post_stack);
        }
    }
    reverse_post_stack.push(v); // ������ڵݹ����֮�󽫶���ѹ��ջ
}

void Graph::printStronglyConnectedComponent() {
    // marked��������ѷ��ʹ��Ľ�㣬��ʼֵΪfalse�����ʹ�Ϊtrue
    bool *marked = new bool[num_v_];
    for (int i = 0; i < num_v_; i++) {
        marked[i] = false;
    }
    // ��ȡͼG�ķ���ͼreverse_G
    Graph reverse_G = getReverse();
    // ������ջ��˳���������������˳��
    stack<int> reverse_post_stack;
    for (int v = 0; v < num_v_; ++v) {
        if (!marked[v]) {
            getReversePost(reverse_G, v, marked, reverse_post_stack);
        }
    }
    for (int i = 0; i < num_v_; i++) {
    	marked[i] = false;
    }
    // ���շ���ͼreverse_G������������˳���ͼG����DFS
    while (!reverse_post_stack.empty()) {
        int v = reverse_post_stack.top();
        reverse_post_stack.pop();
        if (!marked[v]) {
            dfs(v, marked);
            cout << endl;
        }
    }
}

// ����
void testKosaraju() {
    Graph G(5);
    G.addEdge(1, 0);
    G.addEdge(0, 2);
    G.addEdge(2, 1);
    G.addEdge(0, 3);
    G.addEdge(3, 4);
    cout << "The strongly connected components in given graph" << endl;
    G.printStronglyConnectedComponent();
}

int main(){
    testKosaraju();
    return 0;
}