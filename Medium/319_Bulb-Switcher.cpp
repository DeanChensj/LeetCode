#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
 
int bulbSwitch(int n) {
        int i = 1;
        for (i = 1; i * i <= n; i++);
        return i-1;
    }
int main(int argc, char const *argv[])
{
    for (int i = 0; i < 101; i++) {
        cout << bulbSwitch(i) << endl;
    }
	return 0;
}
