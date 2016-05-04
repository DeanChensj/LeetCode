#include "../Header.h"

using namespace std;
int integerBreak(int n) {
    if (n == 2) return 1;
    else if (n == 3) return 2;
    else if (n == 4) return 4;
    else if (n == 5) return 6;
    else if (n == 6) return 9;
    else return 3 * integerBreak(n - 3);
}
int main(int argc, char const *argv[])
{
	return 0;
}
