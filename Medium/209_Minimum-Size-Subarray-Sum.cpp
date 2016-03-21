#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int min(INT_MAX), sum(0), cnt(0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            cnt++;
            if (sum >= s) {
                while (sum >= s) {
                    if(cnt < min) min = cnt;
                    sum -= nums[i-(--cnt)];
                }
            }
        }
        
        return min == INT_MAX ? 0 : min;
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
    cout << minSubArrayLen(7, num) << endl;
	return 0;
}
