/*! Author: qwchen
 *! Date: 2016-9-22
 * �ö���ʵ�ֵĲ����Թ�����������·��
 * ��������������һ���Թ������Թ�������������start��end��Ѱ�Ҵ�start��end�����·��
 * ˼·��һ�ֹ����������
 *       ����ԭʼ���Թ�����(maze)������ÿ�����㵽���ľ��롣��Ϊ0���������ͨ·��1������ϰ���������Ǵ�2��ʼ����������þ��붼��ȥ2���ɡ�
 *       ����㿪ʼ�����ϵĽ���ǰ����ı��Ϊ0���ھӱ��Ϊ��ǰ����ı��+1������������С�Ȼ��Ӷ�ͷȡ����㣬�ظ��ù��̡�
 *       ֱ���ҵ�end��� �� ����Ϊ�գ��Ҳ���end��㣩������ѭ����
 *       �����ҵ�end���ʱ��mazeÿ����0��1���ͼ�¼�Ÿý�㵽start���ľ���+2��
 *       ��end��㿪ʼÿ�εݼ�1����������start��㣬�����÷���·�����浽ջ�С�
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// ��һ���㶨��Ϊһ���ṹ��(x, y)
struct position {
    int row;
    int col;
    position() {}
    position(int row, int col) {
        this->row = row;
        this->col = col;
    }
};

/*Ѱ���Թ��������·���ĺ����㷨*/
bool findShortPath(vector<vector<int>> maze, position start, position end, stack<position> &path, int &pathLength) {
    if (start.row == end.row && start.col == end.col) {
        return true;
    }
    // ��ʼ��ƫ����
    position offset[4];
    offset[0].row = 0, offset[0].col = 1;  // ��
    offset[1].row = 1, offset[1].col = 0;  // ��
    offset[2].row = 0, offset[2].col = -1; // ��
    offset[3].row = -1, offset[3].col = 0; // ��
    int numberOfNeig = 4;
    position current = start;
    maze[current.row][current.col] = 2;  // ��0����δ�ߵĽ�㣬1�����ϰ���>=2����������룬��󽫾��붼-2�Ϳ��Եõ������ľ���
    position neig;
    queue<position> queue;
    while (true) {
        // ��һ��������Χ�Ǹ���㣬�������end��㡢�����ϰ���㡢Ҳ�����߹��Ľ�㣬
        // ����Ϊ��ǰ���ľ���+1�����ŵ�������
        for (int i = 0; i < numberOfNeig; i++) {
            neig.row = current.row + offset[i].row;
            neig.col = current.col + offset[i].col;
            if (maze[neig.row][neig.col] == 0) {
                maze[neig.row][neig.col] = maze[current.row][current.col] + 1;
                queue.push(neig);
            }
            // ����ҵ�end��㣬�˳���ѭ��
            if (neig.row == end.row && neig.col == end.col) {
                break;
            }
        }
        if (neig.row == end.row && neig.col == end.col) { // �ҵ�ʱ������ѭ��
            break;    
        }
        // ����Ϊ��ʱ��˵���Ҳ���end��㣬������ѭ��������false
        if (queue.empty()) { 
            return false;
        }
        current = queue.front();
        queue.pop();
    }
    pathLength = maze[end.row][end.col] - 2;
    current = end;
    for (int i = pathLength - 1; i >= 0; i--) {
        path.push(current);
        for (int j = 0; j < numberOfNeig; j++) {
            neig.row = current.row + offset[j].row;
            neig.col = current.col + offset[j].col;
            if (maze[neig.row][neig.col] == i + 2) 
                break;
        }
        current = neig;
    }
    path.push(start);
    return true;
}


void testfindShortPath() {
    const int numberOfRow = 7;
    const int numberOfCol = 7;
    // 7 * 7���Թ�����0��8����Χ����һȦ�ϰ�����㷨
    // ����0��ʾ����·����1��ʾ�ϰ���
    vector<vector<int>> maze = {
        { 1,1,1,1,1,1,1,1,1 },
        { 1,0,0,1,0,0,0,0,1 },
        { 1,0,0,1,1,0,0,0,1 },
        { 1,0,0,0,0,1,0,0,1 },
        { 1,0,0,0,1,1,0,0,1 },
        { 1,1,0,0,0,1,0,0,1 },
        { 1,1,1,1,0,0,0,0,1 },
        { 1,1,1,1,0,0,0,0,1 },
        { 1,1,1,1,1,1,1,1,1 }
    };
    for (int i = 0; i < numberOfRow + 2; i++) {
        for (int j = 0; j < numberOfCol + 2; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    int pathLength = 0;    // ���·������
    stack<position> path;  // ���·������
    position start(3, 2);  // ���
    position end(4, 6);    // �յ�
    if (findShortPath(maze, start, end, path, pathLength)) {
        cout << "Have short path. ";
        cout << "It 's long is " << pathLength << "." << endl;
        while(!path.empty()){
            position current = path.top();
            path.pop();
            cout << "(" << current.row << ", " << current.col << ")" << endl;
        }
    }
    else {
        cout << "No short path." << endl;
    }
}

int main(){
    testfindShortPath();
}