#include "../Header.h"

using namespace std;
static bool greater(const string &a, const string &b) {
    return a+b > b+a;
}

string largestNumber(vector<int>& nums) {
    vector<string> v;
    for (auto n : nums) v.push_back(to_string(n));
    sort(v.begin(), v.end(), greater);
    string result = "";
    for (auto s : v) result += s;
    while(result[0] == '0' && result.length() > 1)
        result.erase(0,1);
    return result;   
}
int main(int argc, char const *argv[])
{
	return 0;
}
