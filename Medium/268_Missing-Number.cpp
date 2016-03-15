#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
 
int missingNumber(vector<int>& nums) {
    int n = nums.size(); 
    long sum = 0, expect = (1 + n) * n / 2;
    
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    return expect - sum;
}

int main(int argc, char const *argv[])
{
    vector<int> num;
    num.push_back(0);
    num.push_back(1);
    num.push_back(3);
    
    cout << missingNumber(num) << endl;
	return 0;
}
