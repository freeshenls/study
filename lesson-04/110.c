#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root)
{
    int left = countLeaf(root->left, 1);
    int right = countLeaf(root->right, 1);
    // printf("left=========%d\n", left);
    // printf("right=========%d\n", right);

    if (left - right > 1 || right - left > 1)
    {
        return false;
    }
    return true;
}

int countLeaf(struct TreeNode* root, int count)
{
    int leftCount = count + 0;
    int rightCount = count + 0;
    if (!root)
    {
        return count;
    }

    if (root->left)
    {
        leftCount = countLeaf(root->left, count + 1);
    }

    if (root->right)
    {
        rightCount = countLeaf(root->right, count + 1);
    }

    return leftCount > rightCount ? leftCount : rightCount;
}

int main(int argc, char const *argv[])
{
    // struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // struct TreeNode t9, t15, t20, t7;
    // root->val = 3;
    // t9.val = 9;
    // t9.left = NULL;
    // t9.right = NULL;
    // t15.val = 15;
    // t15.left = NULL;
    // t15.right = NULL;
    // t20.val = 20;
    // t7.val = 7;
    // t7.left = NULL;
    // t7.right = NULL;
    // root->left = &t9;
    // root->right = &t20;
    // t20.left = &t15;
    // t20.right = &t7;

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode t1, t21, t22, t31, t32, t41, t42;
    root->val = 1;
    t21.val = 2;
    t22.val = 2;
    t22.left = NULL;
    t22.right = NULL;
    t31.val = 3;
    t32.val = 3;
    t32.left = NULL;
    t32.right = NULL;
    t41.val = 4;
    t41.left = NULL;
    t41.right = NULL;
    t42.val = 4;
    t42.left = NULL;
    t42.right = NULL;
    root->left = &t21;
    root->right = &t22;
    t21.left = &t31;
    t21.right = &t32;
    t31.left = &t41;
    t31.right = &t42;

    bool result = isBalanced(root);
    printf("%d\n", result);
    free(root);
    return 0;
}
