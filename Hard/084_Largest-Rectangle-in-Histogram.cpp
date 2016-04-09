#include "../Header.h"

using namespace std;
int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0, sz = heights.size();
    stack<int> lastIndex;
    for (int i = 0; i < sz; i++) {
        while (!lastIndex.empty() && heights[lastIndex.top()] > heights[i]) {
            int l = lastIndex.top();
            lastIndex.pop();
            // w+1 代表的坐标是高度不小于当前高度的最左边的坐标
            // 栈空代表当前高度为目前为止的最低高度
            int w = lastIndex.empty() ? -1 : lastIndex.top();
            maxArea = max(maxArea, heights[l] * (i - (w + 1)));
        }
        lastIndex.push(i);
    }
    // 处理递增数列
    while (!lastIndex.empty()) {
        int l = lastIndex.top();
        lastIndex.pop();
        int w = lastIndex.empty() ? -1 : lastIndex.top();
        maxArea = max(maxArea, heights[l] * (sz - (w + 1)));
    }
    return maxArea;
}
int main(int argc, char const *argv[])
{
    vector<int> v = genRandVector(10, 10);
	cout << "v = " << toString(v) << endl;
    cout << "largestRectangleArea(v) = " << largestRectangleArea(v) << endl;
	return 0;
}
