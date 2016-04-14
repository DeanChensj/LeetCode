#include "../Header.h"

using namespace std;
int numSquares(int n) {
    bool *isVisited = new bool[n+1];
    memset(isVisited, 0, n+1);
    vector<int> squares;
    queue<int> BFS;
    for (int i = 1; i*i <= n; i++) {
        int t = i*i;
        if (t == n) return 1;
        squares.push_back(t);
        BFS.push(t);
        isVisited[t] = 1;
    }
    int curLevelCnt = 0, curLevel = 1, preLevelCnt = squares.size();
   
    while(1) {
        curLevel++;
        while(preLevelCnt--) {
            int num = BFS.front();
            BFS.pop();
            for (auto square: squares) {
                int t = num + square;
                if (t == n) return curLevel;
                if (t > n) break;
                if (!isVisited[t]) {
                    curLevelCnt++;
                    isVisited[t] = 1;
                    BFS.push(t);
                }
                
            }
        }
        preLevelCnt = curLevelCnt;
    }
}
int main(int argc, char const *argv[])
{
    srand((int)time(NULL));
	int num = random(9999);
    cout << num << " " << numSquares(num) << endl;
	return 0;
}
