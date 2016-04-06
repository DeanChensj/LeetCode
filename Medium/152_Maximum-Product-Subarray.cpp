#include "../Header.h"

using namespace std;
int maxProduct(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int leftNeg = 1, negCnt = 0, curPos = 1, tmpProduct = 1, maxProduct = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (!nums[i]) {
            if (0 > maxProduct) maxProduct = 0;
            leftNeg = 1;
            curPos = 1;
            tmpProduct = 1;
            negCnt = 0;
        } else if (nums[i] > 0) {
            curPos *= nums[i];
            maxProduct = max(curPos, maxProduct);
            if (!(negCnt & 1)) maxProduct = max (maxProduct, curPos * tmpProduct);
            else maxProduct = max (maxProduct, curPos * tmpProduct / leftNeg);
        } else {
            tmpProduct *= curPos * nums[i];
            if (++negCnt & 1) {
                int t = tmpProduct / leftNeg;
                maxProduct = max(t, maxProduct);
            } else maxProduct = max(maxProduct, tmpProduct);
            curPos = 1;
            if (leftNeg == 1) leftNeg = tmpProduct;
        }
    }
    return maxProduct;
}
int main(int argc, char const *argv[])
{
    srand((int)time(NULL));
	vector<int> nums = genRandVector(10, 10);
    
    cout << toString(nums) << endl;
    cout << maxProduct(nums) << endl;
	return 0;
}
