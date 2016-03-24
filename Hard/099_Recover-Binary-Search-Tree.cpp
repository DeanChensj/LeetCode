#include "../Header.h"
#include "../TreeNode.h"

using namespace std;
int pre = INT_MIN;
TreeNode* preNode = NULL;
void inOrderTraverse(TreeNode* root, vector<TreeNode*> &v) {
    if (root->left) inOrderTraverse(root->left, v);
    if (root->val < pre){ 
        v.push_back(preNode);
        v.push_back(root);
    }
    pre = root->val;
    preNode = root;
    if (root->right) inOrderTraverse(root->right, v);
}

void recoverTree(TreeNode* root) {
    vector<TreeNode*> treeVec;
    inOrderTraverse(root, treeVec);
    TreeNode *a, *b;
    if (treeVec.size() == 2) {
        a = treeVec[0];
        b = treeVec[1];
    } else {
        a = treeVec[0];
        b = treeVec[3];
    }
    swap(a->val, b->val);
    }

int main(int argc, char const *argv[])
{
    
	return 0;
}
