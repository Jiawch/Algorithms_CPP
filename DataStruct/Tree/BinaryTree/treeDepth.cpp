/*! Author: Jiawch
 *! Date  : 2021-10-25
 *  二叉树的高度
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
