#include "../Header.h"

using namespace std;
 TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
    if (pl > pr) return nullptr;
    TreeNode *root = new TreeNode(postorder[pr]);
    int i = il;
    for (; i <= ir; i++) {
        if (inorder[i] == postorder[pr]) break;
    }
    int t = pr-ir+i;
    root->left = buildHelper(inorder, postorder, il, i-1, pl, t-1);
    root->right = buildHelper(inorder, postorder, i+1, ir, t, pr-1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int sz = postorder.size() - 1;
    return buildHelper(inorder, postorder, 0, sz, 0, sz);
}

int main(int argc, char const *argv[])
{
	return 0;
}
