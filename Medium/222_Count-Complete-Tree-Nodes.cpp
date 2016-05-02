#include "../Header.h"
#include "../TreeNode.h"

using namespace std;
int height(TreeNode *root) {
    TreeNode *node = root;
    int h = 0;
    while (node) {
        h++;
        node = node->left;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int res = 0, h;
    while (root) {
        res++;
        h = height(root->left);
        if (height(root->right) == h) { // the last node is in the right subTree
            res += (1 << h) - 1;
            root = root->right;
        } else { // the last node is in the left subTree
            res += (1 << (h-1)) - 1;
            root = root->left;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
	return 0;
}
