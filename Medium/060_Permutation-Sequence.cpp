#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <stdio.h>
using namespace std;
    string getPermutation(int n, int k) {
        list<int> sortedList;
        int *array = new int[n+1];
        array[0] = 1;
        for (int i = 1; i <= n; i++) {
            array[i] = array[i-1] * i;
            sortedList.push_back(i);
        }

        k--;
        int numLeft = n-1;
        list<int>::iterator it;
        string ans = "";
        while (!sortedList.empty()) {
            int nth = k / array[numLeft], i = 0;
            for(it = sortedList.begin(); i < nth && it != sortedList.end(); i++, it++);
            ans += '0' + *it;
            sortedList.erase(it);
            k -= nth * array[numLeft--];
        }
        return ans;
    }

int main(int argc, char const *argv[])
{
    cout << getPermutation(3, 6) << endl;
	return 0;
}
