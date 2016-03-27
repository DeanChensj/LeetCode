#include "../Header.h"

using namespace std;
int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int sz = citations.size(), l = 0, r = sz - 1;
        while (l <= r) {
            int mid = (l+r) >> 1;
            if (sz - mid > citations[mid])  l = mid + 1;
            else if (sz - mid == citations[mid]) return citations[mid];
            else r = mid - 1;
        }
        return sz - l;
    }

int main(int argc, char const *argv[])
{
	vector<int> citations = genRandVector(10, random(30));
    cout << "citations are: " << toString(citations) << endl;
    cout << "the hIndex is " << hIndex(citations) << endl;
	return 0;
}
