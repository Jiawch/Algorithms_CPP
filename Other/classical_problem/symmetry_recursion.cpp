/* 树的对称性递归
 * ref: https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/yi-pian-wen-zhang-dai-ni-chi-tou-dui-che-uhgs/
 */

/*
题型分类：
可以用对称性递归解决的二叉树问题大多是判断性问题(bool类型函数),这一类问题又可以分为以下两类：

1、不需要构造辅助函数。这一类题目有两种情况：第一种是单树问题，且不需要用到子树的某一部分(比如根节点左子树的右子树)，只要利用根节点左右子树的对称性即可进行递归。第二种是双树问题，即本身题目要求比较两棵树，那么不需要构造新函数。该类型题目如下：
100. 相同的树
226. 翻转二叉树
104. 二叉树的最大深度
110. 平衡二叉树
543. 二叉树的直径
617. 合并二叉树
572. 另一个树的子树
965. 单值二叉树

2、需要构造辅助函数。这类题目通常只用根节点子树对称性无法完全解决问题，必须要用到子树的某一部分进行递归，即要调用辅助函数比较两个部分子树。形式上主函数参数列表只有一个根节点，辅助函数参数列表有两个节点。该类型题目如下：
101. 对称二叉树
剑指 Offer 26. 树的子结构
 */

/* 相同的树
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)   return true;
        if (p == nullptr || q == nullptr)   return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


/* 树的子结构（约定空树不是任意一个树的子结构）
 * 子结构：A是B的子结构，A的根节点不一定是B，也可以是B的子树中任一节点
 * 子树：A是B的子树，A的根节点是B
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {     // B是A的子结构
        if (A == nullptr || B == nullptr)    return false;
        // 要么B是以A为根的子结构，要么B是以A左子树的子结构，要么B是以A右子树的子结构
        return isSubStructureOfRoot(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
private:
    bool isSubStructureOfRoot(TreeNode* A, TreeNode* B) {   // B是以A为根的子结构
        if (B == nullptr)   return true;
        if (A == nullptr)   return false;
        return A->val == B->val && isSubStructrueOfRoot(A->left, B->left) && isSubStructrueOfRoot(A->right, B->right);
    }
};
