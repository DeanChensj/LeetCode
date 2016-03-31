#include "../Header.h"

using namespace std;
int firstBadVersion(int n) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = (l >> 1) + (r >> 1) + (l & 1 & r);
        if (isBadVersion(mid)) r = mid;
        else l = mid + 1;
    }
    return r;
}