#include "../Header.h"
using namespace std;
void rotate(vector<int>& nums, int k) {
    int sz = nums.size();
    k = k % sz;
    if (!k) return;
    vector<int> v;
    for (int i = sz-k; i < sz; i++) v.push_back(nums[i]);
    for (int i = sz-1; i >= k; i--) nums[i] = nums[i-k];
    for (int i = 0; i < k; i++) nums[i] = v[i];
}

int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
	rotate(num, 2);
	for (int i = 0; i < num.size(); i++) cout << num[i] << " ";
	cout << endl;
	return 0;
}