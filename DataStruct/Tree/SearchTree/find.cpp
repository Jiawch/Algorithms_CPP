/*! Author: Jiawch 
 *! Date: 2021-10-26
 * 二叉查找树中（没有重复的值时）的查找
 */

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val): val(val), left(nullptr), right(nullptr) {}
};


/*
 * 查找等于target的节点
 *  从根节点开始查找。如果根为空，那么搜索树不包含任何元素，即查找失败。
 *  如果不为空，则将target与根的关键字比较。
 *      如果 target > 根节点的关键字，则查找左子树。
 *      如果 target < 根节点的关键字，则查找右子树。
 *      如果 target = 根节点的关键字，则查找成功，返回节点。
 */

// 递归版
TreeNode* find (TreeNode* t, int target) {
    if (!t) return t;

    if (target > t->val)
        return find(t->right, target);
    else if (target < t->val)
        return find(t->left, target);
    else
        return t;
}

// 迭代版
TreeNode* findNoRecursion (TreeNode* t, int target) {
    if (!t) return t;

    TreeNode *p = t;
    while (p) {
        if (target > p->val) p = p->right;
        else if (target < p->val) p = p->left;
        else return p;
    }

    return p;
}




/*
 * 查找大于等于target的最小值（递归实现）
 *  如果当前节点为空，那么搜索树不包含任何元素，直接返回节点。
 *  如果不为空，
 *      如果当前节点 > target，则`大于等于target的最小值`在当前节点左子树或者即为当前节点
 *          如果左子树查找为空，则当前节点为所求，否则为左子树返回值
 *      如果当前节点 < target，则`大于等于target的最小值`在当前节点右子树
 *      如果当前节点 = target，则`大于等于target的最小值`为当前节点
 */

// 递归
TreeNode* findGE (TreeNode* t, int target) {
    if (!t) return t;
    if (t->val < target)
        return findGE (t->right, target);
    else if (t->val > target) {
        TreeNode *p = findGE (t->left, target);
        return p == nullptr ? t : p;    // 如果左子树返回空，说明左子树所以值都比target小，即只走`t->val < target`
    } else
        return t;
}


/*
 * 查找大于等于target的最小值（迭代实现）
 *  1. 如果当前节点为空，直接返回节点
 *  2. 如果不为空，
 *      2.1 如果当前节点 > target，说明`大于等于target的最小值`在当前节点或其左子树，
 *          保存当前节点为候选，继续搜索其左子树，即重复第2步
 *      2.2 如果当前节点 < target，说明`大于等于target的最小值`在当前节的右子树，
 *          继续搜索其右子树，即重复第2步
 *      2.3 如果当前节点 = target，则`大于等于target的最小值`为当前节点，返回当前节点。
 *  3. 返回候选者
 */

// 迭代
TreeNode* fineGENoRecursion (TreeNode* t, int target) {
    if (!t) return t;

    TreeNode *p = t,
             *pre = nullptr;
    while (p) {
        if (p->val > target) {
            pre = p;        //  候选
            p = p->left;
        } else if (p->val < target)
            p = p->right;
        else
            return p;
    }

    return pre;
}



/*
 * 查找小于等于target的最大值（递归实现）
 *  如果当前节点为空，那么搜索树不包含任何元素，直接返回节点。
 *  如果不为空，
 *      如果当前节点 > target，则`小于等于target的最大值`在当前节点左子树
 *      如果当前节点 < target，则`小于等于target的最大值`在当前节点右子树或当前节点
 *          如果右子树查找返回空，则当前节点为所求，否则为右子树返回值
 *      如果当前节点 = target，则`小于等于target的最大值`为当前节点
 */

// 递归
TreeNode* findLE (TreeNode* t, int target) {
    if (!t) return t;
    if (target > t->val) {
        TreeNode* p = findLE (t->right, target);
        return p == nullptr ? t : p;
    } else if (target < t->val) 
        return findLE (t->left, target);
    else
        return t;
}


// 迭代
TreeNode* findLENoRecursion (TreeNode* t, int target) {
    if (!t) return t;

    TreeNode *p = t,
             *pre = nullptr;
    while (p) {
        if (p->val > target)
            p = p->left;
        else if (p->val < target) {
            pre = p;        // 候选
            p = p->right;
        }
        else
            return p;
    }

    return pre;
}




/*
 *     10
 *    /   \
 *   5    18
 *  / \   / \
 * 1   7 16 19
 *    /    \
 *   6     17
 *
 */

int main () {
    TreeNode *node10 = new TreeNode(10);    // root
    TreeNode *node5 = new TreeNode(5);
    node10->left = node5;
    TreeNode *node18 = new TreeNode(18);
    node10->right = node18;

    TreeNode *node1 = new TreeNode(1);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node17 = new TreeNode(17);
    TreeNode *node19 = new TreeNode(19);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node16 = new TreeNode(16);

    node5->left = node1;
    node5->right = node7;
    node7->left = node6;
    node18->left = node16;
    node18->right = node19;
    node16->right = node17;

    TreeNode *p;
    int target = 15;

    // 查找等于target的节点
    p = find(node10, target);
    if (p) cout << "find: " << p->val << endl;
    else cout << "find: " << target << " is not found!" << endl;

    // 查找等于target的节点（迭代）
    p = findNoRecursion(node10, target);
    if (p) cout << "findNoRecursion: " << p->val << endl;
    else cout << "findNoRecursion: " << target << " is not found!" << endl;    

    // 查找大于等于target的最小节点
    p = findGE(node10, target);
    if (p) cout << "findGE: " << p->val << endl;
    else cout << "findGE: " << target << " is not found!" << endl;

    // 查找大于等于target的最小节点（迭代）
    p = fineGENoRecursion(node10, target);
    if (p) cout << "fineGENoRecursion: " << p->val << endl;
    else cout << "fineGENoRecursion: " << target << " is not found!" << endl;

    // 查找小于等于target的最大节点
    p = findLE(node10, target);
    if (p) cout << "findLE: " << p->val << endl;
    else cout << "findLE: " << target << " is not found!" << endl;  

    // 查找小于等于target的最大节点（迭代）
    p = findLENoRecursion(node10, target);
    if (p) cout << "findLENoRecursion: " << p->val << endl;
    else cout << "findLENoRecursion: " << target << " is not found!" << endl;  
    
    return 0;
}

/* Result:
    find: 15 is not found!
    findNoRecursion: 15 is not found!
    findGE: 16
    fineGENoRecursion: 16
    findLE: 10
    findLENoRecursion: 10
 */


