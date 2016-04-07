#include "../Header.h"
#include "../TreeNode.h"

using namespace std;
TreeNode * LCA = nullptr;
char helper(TreeNode* root, TreeNode* p, TreeNode* q) {
    char flag = 0;
    if (root->left) flag |= helper(root->left, p, q);
    if (root->right) flag |= helper(root->right, p, q);
    if (root == p) flag |= 2;
    if (root == q) flag |= 1;
    if (flag  == 3) {
        LCA = root;
        return 0;
    } else return flag;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!p) return q;
    if (!q) return p;
    helper(root, p, q);
    return LCA;
}

