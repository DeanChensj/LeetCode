#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
 int minPatches(vector<int>& nums, int n) {
        long missingLeastSum = 1;
        int pathCnts = 0, i = 0;
        while (missingLeastSum <= n) {
            if (i >= nums.size() || nums[i] > missingLeastSum) {
                pathCnts++;
                missingLeastSum <<= 1;
            } else {
                missingLeastSum += nums[i++];
            }
        }
        return pathCnts;
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
