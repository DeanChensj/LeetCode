#include "../Header.h"
using namespace std;
int nthUglyNumber(int n) {
    int x2(1), x3(1), x5(1);
    vector<int> nth(n+1, 1);
    
    for (int i = 2; i <= n; i++) {
        nth[i] = min(nth[x2] * 2, min(nth[x3] * 3, nth[x5] * 5));
        if (nth[i] == nth[x2] * 2) x2++;
        if (nth[i] == nth[x3] * 3) x3++;
        if (nth[i] == nth[x5] * 5) x5++;
    }

    return nth[n];
    
}
int main(int argc, char const *argv[])
{
	
    cout << nthUglyNumber(100) << endl;
	return 0;
}
