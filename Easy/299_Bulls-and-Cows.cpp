#include "../Header.h"

using namespace std;
   string getHint(string secret, string guess) {
        vector<int> cnt(10, 0);
        int A = 0, B = 0;
        for (int i = 0; i < secret.length(); i++) {
            cnt[secret[i] - '0']++;
        }
        
        for (int i = 0; i < secret.length(); i++) {
            int num = guess[i] - '0';
            if (secret[i] == guess[i]) {
                A++;
                cnt[num]--;
            }
        }
        for (int i = 0; i < secret.length(); i++) {
            int num = guess[i] - '0';
            if (secret[i] != guess[i] && cnt[num]) {
                cnt[num] = cnt[num] > 0 ? cnt[num] - 1 : 0;
                B++;
            }
        }
        return to_string(A) + 'A' + to_string(B) + 'B';
    }

int main(int argc, char const *argv[])
{
	cout << getHint("1207", "7201") << endl;
	return 0;
}