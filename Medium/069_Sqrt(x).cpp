#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;
    int mySqrt(int x) {
        if (!x || x == 1) return x; 
 
        long high = min(x >> 1, 0x1FFFF), low = 1;
        while (low <= high) {
            long mid = (low+high) >> 1, square = mid * mid;
            if (square == x) return mid;
            else if (square < x) {
                if ((mid + 1) * (mid + 1) > x) return mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }

int main(int argc, char const *argv[])
{
    int i = 0x7FFFFFFF;
    printf("sqrt(%d) = %d, should be %d\n", i, mySqrt(i), (int) sqrt(i));
	return 0;
}
