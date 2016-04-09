#include "../Header.h"

using namespace std;
vector<int> singleNumber(vector<int>& nums) {
    int xory = 0, pos = 1, x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++) xory ^= nums[i];
    while (xory) {
        if (xory & 1) break;
        xory >>= 1;
        pos <<= 1;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] & pos) x ^= nums[i];
        else y ^= nums[i];
    }
    return vector<int>{x, y}
}

