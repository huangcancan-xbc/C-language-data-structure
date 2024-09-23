﻿#define _CRT_SECURE_NO_WARNINGS 1

//力扣：101. 对称二叉树
//https://leetcode.cn/problems/symmetric-tree/description/

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (q == NULL || p == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left, root->right);
}