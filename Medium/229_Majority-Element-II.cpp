#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.size() < 2) return nums;
        
        int flag = nums.size() / 3;
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]]++;
            if (hash_map[nums[i]] > flag) {
                if (res.size() == 0) {
                    res.push_back(nums[i]);
                } else if (res.size() == 1 && res[0] != nums[i]) {
                    res.push_back(nums[i]);
                    break;
                }
            }
        }
        return res;
    }

int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(6);
    num.push_back(4);
    num.push_back(3);
    num.push_back(3);
    majorityElement(num);
	return 0;
}
