/*! Author: Jiawch 
 *! Date: 2021-10-26
 * 二叉查找树中（没有重复的值时）的插入
 */

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val): val(val), left(nullptr), right(nullptr) {}
};


/* 二叉查找树的插入（递归）
 * 如果当前节点为空，返回new节点
 * 如果当前节点不为空，
 *  1. 当前节点的值>插入值，那么在左子树进行插入
 *  2. 当前节点的值<插入值，那么在右子树进行插入
 * 返回根节点
 */
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val > val)
        root->left = insert(root->val, val);
    else
        root->right = insert(root->right, val);
    return root;
}


/* 二叉查找树的插入（迭代）
 * 如果当前节点为空，返回new节点
 * 如果当前节点不为空，
 *  1. 当前节点的值>插入值，左节点存在则往左走，否则插入新节点
 *  2. 当前节点的值<插入值，右节点存在则往右走，否则插入新节点
 */
TreeNode* insertNoRecursion(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    TreeNode* p = root;
    while (p) {
        if (p->val > val) {
            if (p->left) p = p->left;
            else {
                p->left = new TreeNode(val);
                break;
            }
        }
        else {
            if (p->right) p = p->right;
            else {
                p->right = new TreeNode(val);
                break;
            }
        }
    }
    return p;
}
