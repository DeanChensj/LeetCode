#include <iostream>
#include <vector>
#include <queue>
using namespace std;

   int jump(vector<int>& nums) {
        int size = nums.size() - 1;
        if (size == 0) return 0;
        int cnt = 1, n = 0, newN = 0, i = 0;
        
        while (1) {
            for (; i <= n; i++) {
                newN = max(newN, nums[i] + i);
            }
            if (newN >= size) return cnt;
            n = newN;
            cnt++;
        }
    }

int main(int argc, char const *argv[])
{
  vector<int> num;
  num.push_back(2);
  num.push_back(3);
  num.push_back(1);
  num.push_back(1);
  num.push_back(4);
	cout << jump(num) << endl;
	return 0;
}
