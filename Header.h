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
using namespace std;

int random(int x) {
    return rand() % x + 1;
}

vector<int> genRandVector(int len, int maxVal){
    vector<int> v(len, 0);
    srand((int)time(NULL));
    for (int i = 0; i < len; ++i)
    {
        v[i] = random(maxVal);
    }
    return v;
}


vector<int> genOrderedVector(int len){
    vector<int> v(len, 0);
    for (int i = 1; i <= len; ++i)
    {
        v[i-1] = i;
    }
    return v;
}

vector<string> genStrVector(string str){
    vector<string> v;
    int i = 0, j;
    while (i < str.length()) {
        while (i < str.length() && str[i] == ' ') i++;
        j = 0;
        for (; i+j < str.length() && str[i+j] != ' '; j++);
        v.push_back(str.substr(i, j));
        i += j;
    }
    return v;
}

string toString(vector<int> v) {
    string res = "[";
    for (int i = 0; i < v.size() - 1; i++){
        res += to_string(v[i]) + ", ";
    }
    res += to_string(v[v.size() - 1]) + "]";
    return res;
}

string toString(vector<string> v) {
    string res = "[";
    for (int i = 0; i < v.size() - 1; i++){
        res += v[i] + ", ";
    }
    res += v[v.size() - 1] + "]";
    return res;
}

#endif 
