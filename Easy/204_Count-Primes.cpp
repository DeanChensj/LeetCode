#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
  int countPrimes(int n) {
        int cnt = 0;
        bool *isPrime = new bool[n];
        for (int i = 0; i < n; i++) isPrime[i] = 1;
        for (int i = 2; i < n; i++) {
            if (isPrime[i])
                for (int j = 2*i; j < n; j += i) {
                    isPrime[j] = 0;
                }
        }
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) cnt++;
        }
        return cnt;
    }

int main(int argc, char const *argv[])
{
	cout << countPrimes(100) << endl;
	return 0;
}