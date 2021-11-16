
/*! Author: Jiawch
 *! Date: 2021-11-16
 * 二叉查找树的删除
 * 如果当前节点<目标节点，去右子树删除
 * 如果当前节点>目标节点，去左子树删除
 * 如果当前节点=目标节点，分种情况：
 *  1. 当前节点为叶子节点，直接删除
 *  2. 当前节点只有左孩，左子树顶替当前节点
 *  3. 当前节点只有右孩，右子树顶替当前节点
 *  4. 当前节点既有左孩又有右孩，寻找当前节点的后继（右子树的最小值）顶替当前节点
 */

// 在查找树中删除目标节点，并返回根节点
TreeNode* deleteNode(TreeNode* root, int target)
{
    if (root == nullptr)
    {
        return root;
    }

    // 如果当前节点<目标节点，去右子树删除
    if (root->value < target)
    {
        root->right = deleteNode(root->right, target);
    }
    // 如果当前节点>目标节点，去左子树删除
    else if (root->value > target)
    {
        root->left = deleteNode(root->left, target);
    }
    // 如果当前节点=目标节点，分种情况：
    else
    {
        // 当前节点为叶子节点，直接删除
        if (root->left == nullptr && root->right == nullptr)
        {
            return nullptr;
        }
        // 当前节点只有左孩，左子树顶替当前节点
        else if (root->left)
        {
            return root->right;
        }
        // 当前节点只有右孩，右子树顶替当前节点
        else if (root->right)
        {
            return root->left;
        }
        // 当前节点既有左孩又有右孩
        else
        {
            // 寻找当前节点的中序后继节点，即右子树中最左子节点
            TreeNode *p = root->right,
                     *pre = root;

            while (p->left != nullptr)
            {
                pre = p;
                p = p->left;
            }

            // 先删除最左子节点
            if (pre == root)    // 后继节点为右子树
            {
                pre->right = p->right;
            }
            else                // 否则
            {
                pre->left = p->right;
            }

            // 再删除当前节点
            root->value = p->value;
        }
    }

    return root;
}












