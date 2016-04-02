#include "../Header.h"

using namespace std;
int *sum;
NumArray(vector<int> &nums) {
    if (nums.size()) {
        sum = new int[nums.size()+1];
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }
    
}

int sumRange(int i, int j) {
    if (i <= j) {
        return sum[j+1] - sum[i];
    } 
    return 0;
}