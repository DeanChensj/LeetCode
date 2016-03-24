#include "../Header.h"
#include "../TreeNode.h"
using namespace std;

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(!root) return res;
    queue<TreeNode*> q;
    queue<string> qs;
    q.push(root);
    qs.push("");
    while (!q.empty()) {
        TreeNode* tmpNode = q.front();
        q.pop();
        string tmpString = qs.front();
        qs.pop();
        
        tmpString += to_string(tmpNode->val);
        if (tmpNode->left || tmpNode->right) {
            tmpString += "->";
            if (tmpNode->left) {
                q.push(tmpNode->left);
                qs.push(tmpString);
            }
            if (tmpNode->right) {
                q.push(tmpNode->right);
                qs.push(tmpString);
            }
        } else {
            res.push_back(tmpString);
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
	int a[7] = {1, 2, 3, 4, 5, 6, 7};  
    vector<int> v(a, a+7);
    TreeNode *root = buildTree(v);
	vector<string> vec = binaryTreePaths(root);
	for (auto i: vec) cout << i << endl;
	return 0;
}