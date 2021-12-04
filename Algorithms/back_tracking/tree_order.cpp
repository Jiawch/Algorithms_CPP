/*! 
 * DFS 实现树的四种遍历
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
