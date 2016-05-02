#include "../Header.h"

using namespace std;
string convertToTitle(int n) {
    string nums = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", res = "";
    while (n--) {
        res = nums[n % 26] + res;
        n /= 26;
    }
    return res;
}
int main(int argc, char const *argv[])
{
	int n = random(100);
	cout << n << " to " << convertToTitle(n);
	return 0;
}