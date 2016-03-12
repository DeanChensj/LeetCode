#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
using namespace std;
    int findDuplicate(vector<int>& nums) {
        int size = nums.size() - 1, left(1), right(size);
        while (left < right) {
            int mid = (left + right) >> 1, cnt = 0;
            for (int i = 0; i <= size; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }
            if (cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            } 
        }
        return left;
    }

int main(int argc, char const *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(3);
    num.push_back(3);
    num.push_back(2);
	cout << findDuplicate(num) << endl;
	return 0;
}
