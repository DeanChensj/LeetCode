#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

   int helper(TreeNode* root, bool flag) {
        int ans = root->val;
        
        // find max
        if (flag) {
            ans = root->left ? max(ans, helper(root->left, 1)): ans;
            ans = root->right ? max(ans, helper(root->right, 1)): ans;
        } else {
            ans = root->left ? min(ans, helper(root->left, 0)): ans;
            ans = root->right ? min(ans, helper(root->right, 0)): ans;
        }
        return ans;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool left = 1, right = 1;
        int min = root->val+1, max = min-2;
        if (root->left) {
            if (root->val > root->left->val) {
                left = isValidBST(root->left);
                max = helper(root->left, 1);
            } else return false;
            if (!left) return false;
            if (max >= root->val) return false;
        }
        
        if (root->right) {
            if (root->val < root->right->val) {
                right = isValidBST(root->right);
                min = helper(root->right, 0);
            } else return false;
            if (min <= root->val) return false;
        }
        
        return right;
    }

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}

int main()
{
    cout << isValidBST(NULL) << endl;

    int a[]={1,1};
    cout << isValidBST(createTree(a, sizeof(a)/sizeof(int))) << endl;
    
    int b[]={4,2,6,1,7,5,7};
    cout << isValidBST(createTree(b, sizeof(b)/sizeof(int))) << endl;

    int c[]={4,2,6,1,3,5,7};
    cout << isValidBST(createTree(c, sizeof(c)/sizeof(int))) << endl;
    return 0;
}
