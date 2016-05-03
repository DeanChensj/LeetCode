#include "../Header.h"

using namespace std;
bool isPowerOfFour(int num) {
    int n = 1;
    while (n) {
        if (n == num) return 1;
        n <<= 2;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
	return 0;
}