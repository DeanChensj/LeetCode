#include "../Header.h"
##include "../TreeNode.h"

using namespace std;
TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
    if (pl > pr) return nullptr;
    TreeNode *root = new TreeNode(preorder[pl]);
    int i = il;
    for (; i <= ir; i++) {
        if (inorder[i] == preorder[pl]) break;
    }
    root->left = buildHelper(preorder, inorder, pl+1, pl+i-il, il, i-1);
    root->right = buildHelper(preorder, inorder, pl+i-il+1, pr, i+1, ir);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildHelper(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
}
int main(int argc, char const *argv[])
{
	return 0;
}
