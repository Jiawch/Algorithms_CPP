/*!
 * 图DFS
构造一个visit数组表示是否被访问
DFS(数组/图，参数):
    if (满足条)   return;
    for 枚举
        if 未被访问
            选择
            DFS(数组，参数)
            撤销

 * 全排列为例：
 *  画类树图
 *  要求每一条路径，则需要两个变量，
 *  保存路径度变量array，保存全部路径度变量matrix
 */

vector<bool> visited(MAX);  // 默认为0，即为false
void permutation(vector<int> nums, vector<int>& array, vector<vector<int>>& matrix) {
    // 递归结束条件
    if (nums.size() == array.size()) {
        matrix.push_back(array);
        return;
    }

    // for
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i] == false) {
            // 选择
            array.push_back(nums[i]);
            visited[i] = true;
            // DFS
            permutation(nums, array, matrix);
            // 撤销
            array.pop_back();
            visited[i] = false;
        }
    }
}
