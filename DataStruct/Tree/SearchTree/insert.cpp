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

/* 为什么要返回根节点，如果没有返回根节点会如何
 * 正常的算法流程应该是：
 *  如果和更节点一样 -> 不插入
 *  如果小于根节点 -> 在其左子树插入
 *  如果大于根节点 -> 在其右子树插入
 *  递归结束条件则是，当节点为空，new TreeNode(value)。
 *  但这样有一个问题，如何确定new节点是左孩子还是右孩子。
 *  所以，需要把左/右孩子信息记下来，而递归中访问之前信息有二法：
 *      1. 引用变量
 *      2. 递归函数返回值，此法只能访问到上一级
 */

/* 二叉查找树的插入（递归）
 * 如果当前节点为空，返回new节点
 * 如果当前节点不为空，
 *  1. 当前节点的值>插入值，那么在左子树进行插入
 *  2. 当前节点的值<插入值，那么在右子树进行插入
 * 返回根节点
 * highlight: 在查找树root插入value，并返回根节点
 */
TreeNode* insert(TreeNode* root, int value)
{
    if (root == nullptr)
    {
        return new TreeNode(value);
    }

    if (root->value < value)
    {
        root->right = insert(root->right, value);
    }
    else if (root->value > value)
    {
        root->left = insert(root->left, right);
    }

    return root;

}


/* 二叉查找树的插入（迭代）
 * 如果当前节点为空，返回new节点
 * 如果当前节点不为空，
 *  1. 当前节点的值>插入值，左节点存在则往左走，否则插入新节点
 *  2. 当前节点的值<插入值，右节点存在则往右走，否则插入新节点
 */
TreeNode* insert(TreeNode* root, int value)
{
    if (root == nullptr)
    {
        return root;
    }

    TreeNode *p = root;
    while (p != nullptr)
    {
        if (p->value < target)
        {
            if (p->right != nullptr)
            {
                p = p->right;
            }
            else
            {
                p->right = new TreeNode(value);
                break;
            }
        }
        else if (p->value > target)
        {
            if (p->left != nullptr)
            {
                p = p->left;
            }
            else
            {
                p->left = new TreeNode(value);
                break;
            }
        }
        else{
            break;
        }
    }

    return root;
}
