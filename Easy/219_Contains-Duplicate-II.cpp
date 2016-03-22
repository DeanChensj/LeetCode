#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]] = i;
            } else {
                if (i - hash[nums[i]] <= k) return true;
                hash[nums[i]] = i;
            }
        }
        return false;
    }
int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(2);
    num.push_back(3);
    num.push_back(1);
    num.push_back(2);
    num.push_back(4);
    num.push_back(3);
	cout << containsNearbyDuplicate(num, 2) << endl;
	return 0;
}