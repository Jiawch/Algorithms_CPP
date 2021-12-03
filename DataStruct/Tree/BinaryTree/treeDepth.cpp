/*! Author: Jiawch
 *! Date  : 2021-10-25
 *  二叉树的高度
 * ref: https://www.nowcoder.com/profile/700754668/codeBookDetail?submissionId=60132026
 */

int treeHeight (TreeNode* t) {
    if (!t) return 0;
    int lh = treeHeight(t->left);
    int lr = treeHeight(t->right);
    return lh > lr ? lh+1 : lr+1;
}


int treeHeightNoRecursive (TreeNode* t) {
    int high = 0;
    postOrder(t, high);
    return high;
}

// 后序遍历求树高
void postOrder(TreeNode* t, int &high) {
    stack<TreeNode*> s;
    TreeNode *p = t,
             *pre = nullptr;

    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            high = high > s.size() ? high : s.size();
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            if (!p->right || p->right == pre) {
                s.pop()
                pre = p;
                p = nullptr;
            }
            else {
                p = p->right;
            }
        }
    }
}

// 层序遍历求树高
int maxDepth(TreeNode* root) {
    if (root == nullptr)    return 0;
    
    TreeNode *p = root;
    queue<TreeNode*> q;
    q.push(p);
    
    int depth = 0;
    while (!q.empty()) {
        int n = q.size();
        depth++;
        for (int i = 0; i < n; i++) {
            p = q.front();
            q.pop();
            if (p->left != nullptr)    q.push(p->left);
            if (p->right != nullptr)   q.push(p->right);
        }
    }
    
    return depth;
}
