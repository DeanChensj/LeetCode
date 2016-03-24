#ifndef __TREENODE_H__
#define __TREENODE_H__

#include "Header.h"
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int> &vec) {
	TreeNode *root = NULL;
    if(vec.empty() || vec.front() == -1) return root;
    root = new TreeNode(vec.front());
    vector<TreeNode *> pre_level();
    pre_level.push_back(root);
    auto it = vec.begin() + 1;
    while(!pre_level.empty()) {
        vector<TreeNode *> temp;
        for(auto &node : pre_level) {
            if(it != vec.end()) {
                if(*it != -1) {
                    node->left = new TreeNode(*it);
                    temp.push_back(node->left);
                }
                ++it;
            }
            if(it != vec.end()) {
                if(*it != -1) {
                    node->right = new TreeNode(*it);
                    temp.push_back(node->right);
                }
                ++it;
            }
        }
        pre_level = temp;
    }
    return root;
}


#endif 
