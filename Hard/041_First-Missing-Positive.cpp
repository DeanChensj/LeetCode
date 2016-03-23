#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
using namespace std;
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 && nums[0] == 1) return 2;
        for (int i = 0; i < n; i++) {
           while (nums[i] > 0 && nums[i] < n && nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
               swap(nums[i], nums[nums[i]-1]);
           }
        }
        int i;
        for (i = 0; i < n; i++) {
           if (nums[i] != i+1) {
               return i+1;
           }
        }
        return i+1;
    }

int main(int argc, char const *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(4);
    num.push_back(3);
    num.push_back(2);
	cout << firstMissingPositive(num) << endl;
	return 0;
}
