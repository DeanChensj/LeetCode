#include "../Header.h"
#include  "../TreeNode.h"
using namespace std;

class BSTIterator {
private:
    stack<TreeNode*> fathers;
    TreeNode *iterator;
public:
    BSTIterator(TreeNode *root) {
        iterator = root;
        if (iterator) {
            while (iterator->left) {
                fathers.push(iterator);
                iterator = iterator->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iterator != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        int val = iterator->val;
        if (iterator->right) {
            iterator = iterator->right;
            while (iterator->left) {
                fathers.push(iterator);
                iterator = iterator->left;
            } 
        } 
        else if (!fathers.empty()) {
            iterator = fathers.top();
            fathers.pop();
        } else iterator = nullptr;
        return val;
    }
};
int main(int argc, char const *argv[])
{
  
	return 0;
}
