#include "../Header.h"

using namespace std;
int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int cnt = 0, h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (cnt >= citations[i]) return cnt;
            cnt++;
        }
        return cnt;
    }

int main(int argc, char const *argv[])
{
	vector<int> citations = genRandVector(10, random(30));
    cout << "citations are: " << toString(citations) << endl;
    cout << "the hIndex is " << hIndex(citations) << endl;
	return 0;
}
