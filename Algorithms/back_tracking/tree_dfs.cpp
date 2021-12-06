/*! 
 * DFS 实现树的四种遍历, 全排列的组合
 * DFS(节点，参数):
    if (节点为空)   return;
    访问当前节点
    DFS(左子树，参数)
    DFS(右子树，参数)
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 先序遍历
void preOrder(TreeNode* root) {
    if (root == nullptr)    return;

    visit(root);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode* root) {
    if (root == nullptr)    return;

    preOrder(root->left);
    visit(root);
    preOrder(root->right);
}

// 后序遍历
void postOrder(TreeNode* root) {
    if (root == nullptr)    return;

    preOrder(root->left);
    preOrder(root->right);
    visit(root);
}

/*
 * 层序遍历思想：
 *  把每一层的数据单独存到一个数组中,
 *  DFS函数需要加个参数depth(表示当前访问的节点所处的层数)和一个数组(保存结果)
 *  若数组中已经有该层的数据，直接push_back,
 *  否则，再压入一个数组，然后push_back;
 */
// 层序遍历，调用`levelOrder(root, 1, matrix);`； depth从1开始
void levelOrder(TreeNode* root, int depth, vector<vector<int>>& matrix) {
    if (root == nullptr)    return {};

    // 把当前节点放入对应depth的matrix里，如果matrix没有对应对应depth的容器，则创建一个
    if (depth > matrix.size())  matrix.push_back({});
    matrix[depth - 1].push_back(root->val);

    levelOrder(root->left, depth + 1, matrix);
    levelOrder(root->right, depth + 1, matrix);
}


// -------------- 迭代版 ----------------
void preOrderUnRecursive(TreeNode* root) {
    if (root == nullptr)    return;

    stact<TreeNode*> s;
    TreeNode *p = root;

    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            s.push(p);
            visit(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void inOrderUnRecursive(TreeNode* root) {
    if (root == nullptr)    return;

    stact<TreeNode*> s;
    TreeNode *p = root;

    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            visit(p);
            p = p->right;
        }
    }
}

void postOrderNonRecursive(TreeNode* root) {
    if (root == nullptr)    return;

    stack<TreeNode*> s;
    TreeNode *p = root,
             *pre = nullptr;

    while (p != nullptr || !s.empty()) {
        while (p != nullptr) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            if (p->right == nullptr || p->right == pre) {
                s.pop();
                visit(p);
                pre = p;
                p = nullptr;
            } else {
                p = p->right;
            }
        }
    }
}


/*
 * 全排列思想：
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

    // for 枚举
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
