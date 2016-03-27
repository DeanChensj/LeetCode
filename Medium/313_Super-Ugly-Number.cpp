#include "../Header.h"

using namespace std;
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int *nth = new int[n+1], *ptr = new int[primes.size()];
    nth[1] = 1;
    for (int i = 0; i < primes.size(); i++) ptr[i] = 1;
    for (int i = 2; i <= n; i++) {
        nth[i] = nth[ptr[0]] * primes[0];
        for (int j = 1; j < primes.size(); j++) {
            nth[i] = min(nth[i], nth[ptr[j]] * primes[j]);
        }
        
        for (int j = 0; j < primes.size(); j++) {
            if (nth[i] == nth[ptr[j]] * primes[j]) ptr[j]++;
        }
    }
    return nth[n];
}

int main(int argc, char const *argv[])
{
	vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(7);
    cout << "primes are: " << toString(primes) << endl;
    int r = random(100);
    cout << r << "th SuperUglyNumber is " << nthSuperUglyNumber(r, primes) << endl;
	return 0;
}
