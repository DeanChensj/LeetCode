#include "../Header.h"

using namespace std;
vector<int> countBits(int num) {
        vector<int> bits(num+1, 0);
        for (int i = 1; i <= num; i++) bits[i] += bits[i & (i-1)] + 1;
        return bits;
    }

int main(int argc, char const *argv[])
{
    srand((int)time(NULL));
	vector<int> bits = countBits(random(100));
    
    cout << toString(bits) << endl;
	return 0;
}
