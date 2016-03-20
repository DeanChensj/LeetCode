#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
bool isPowerOfThree(int n) {
        return n > 0 && (1162261467 % n == 0);
    }
int main(int argc, char const *argv[])
{
	cout << isPowerOfThree(27) << endl;
	return 0;
}