#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>
using namespace std;
int ChooseKinN(int K, int N) {
    if (N == K || K == 0) return 1;
    else return ChooseKinN(K, N-1) + ChooseKinN(K-1, N-1);
}

int helper(int n) {
    int res = 0;
    for (int i = 1; i <=n; i++) res += ChooseKinN(i, n) * pow(9, n - i) * i;
    return res;
} 

int countDigitOne(int n) {
    if (n <= 0) return 0;
    int count = 0, tmp = n, MSB = 0, res = 0;
    
    while (tmp) {
        count++;
        MSB = tmp % 10;
        tmp /= 10;
    }
    
    int lower = pow(10, count-1), remain = n - lower * MSB; 
    if (MSB == 1) res += remain == 0 ? 1 : remain + countDigitOne(remain) + 1;
    else res += countDigitOne(remain) + lower;
    res += helper(count-1) * MSB;
    
    return res;     
}