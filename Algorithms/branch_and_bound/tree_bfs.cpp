/*! 
 * BFS 
 * - 层序遍历
 * - 求树高
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// 层序遍历
void levelOrder(TreeNode* root, vector<vector<int>> &matrix) {
    if (root == nullptr)    return;

    queue<TreeNode*> q;
    TreeNode *p = root;
    q.push(p);

    while (!q.empty()) {
        int n = q.size();
        vector<int> array;
        while (int i = 0; i < n; i++) {
            p = q.front();
            q.pop();
            array.push_back(p->val);
            if (p->left != nullptr)  q.push(p->left);
            if (p->right != nullptr) q.push(p->right);
        }
        matrix.push_back(array);
    }
}


// 树高
int treeDepth(TreeNode* root) {
    if (root == nullptr)    return 0;

    queue<TreeNode*> q;
    TreeNode *p = root;
    q.push(p);

    int depth = 0;
    while (!q.empty()) {
        int n = q.size();
        depth++;
        while (int i = 0; i < n; i++) {
            p = q.front();
            q.pop();
            if (p->left != nullptr)  q.push(p->left);
            if (p->right != nullptr) q.push(p->right);
        }
    }

    return depth;
}
