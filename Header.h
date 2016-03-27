#ifndef __HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <stdio.h>
#include <list>
#include <map>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <deque>
#include <time.h>


int random(int x) {
    srand((int)time(0));
    return rand() % x + 1;
}

std::vector<int> genRandVector(int len, int maxVal){
    std::vector<int> v(len, 0);
    for (int i = 0; i < len; ++i)
    {
        v[i] = random(maxVal);
    }
    return v;
}

std::vector<int> genOrderedVector(int len){
    std::vector<int> v(len, 0);
    for (int i = 1; i <= len; ++i)
    {
        v[i-1] = i;
    }
    return v;
}

std::string toString(std::vector<int> v) {
    std::string res = "[";
    for (int i = 0; i < v.size() - 1; i++){
        res += std::to_string(v[i]) + ", ";
    }
    res += std::to_string(v[v.size() - 1]) + "]";
    return res;
}

#endif 
