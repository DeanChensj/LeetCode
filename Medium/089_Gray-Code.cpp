#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
  vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (!n) return ans;
        ans.push_back(1);
        if(n == 1) return ans;
        ans.pop_back(); ans.pop_back();
        
        // size 是while操作总次数，实际是个等比数列
        int size = (1<<(n-1)) - 1, cnt = 0; 
        queue<int> q;
        q.push(0); q.push(1);
        /*
         * 先在队列中存入0和1，之后每次从队列中取去两个元素，
         * 并放入四个新元素，分别是原先的元素末尾添1/0和0/1。
         * 用二叉树结构可以方便理解，以下操作实际上是层次遍历。 
         */
        while (!q.empty()) {
            int left = q.front() << 1;
            q.pop();
            int right = q.front() << 1;
            q.pop();
            q.push(left);
            q.push(left + 1);
            q.push(right + 1);
            q.push(right);
            
            cnt++;
            if (cnt == size) break;
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }

int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(31);
    num.push_back(33);
    cout << minPatches(num, 0x7FFFFFFF) << endl;
	return 0;
}
