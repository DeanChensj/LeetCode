#include "../Header.h"

using namespace std;
// 使用deque数据结构，保证可以两头操作队列，每次操作保证window.front()最大
// 每次检查新元素是否比front大，如果是的话，说明在接下来的比较中不会考虑除当前元素以外的元素
// 这样只需将front().first放入答案即可
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int> > window;
    vector<int> max;
    int i;
    for (i = 0; i < k-1; i++) {
        window.push_back(make_pair(nums[i], i));
        while (nums[i] > window.front().first) window.pop_front();
    }
    
    for (; i < nums.size(); i++) {
        if (!window.empty() && window.front().second == i-k) { 
            window.pop_front();
            if (!window.empty()) {
                pair<int, int> tmpMax = window.front();
                for(auto it: window){
                    if (it.first > tmpMax.first) tmpMax = it;
                }
                while (window.front().first < tmpMax.first) window.pop_front();
            }
        }
        
        window.push_back(make_pair(nums[i], i));
        
        while (nums[i] > window.front().first) {
            window.pop_front();
        }
        
        if (i - k + 1 >= 0) max.push_back(window.front().first);
    }
    return max;
}

int main(int argc, char const *argv[])
{
    vector<int> v = genRandVector(10, 10);
	cout << "v = " << toString(v) << endl;
    vector<int> ans = maxSlidingWindow(v, random(10));
    cout << "maxSlidingWindow(v) = " << toString(ans) << endl;
	return 0;
}
