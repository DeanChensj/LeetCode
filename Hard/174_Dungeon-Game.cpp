#include "../Header.h"

using namespace std;
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int h = dungeon.size(), w = dungeon[0].size();
    int **base = new int*[h];
    for (int i = 0; i < h; i++) base[i] = new int[w];
    
    base[h-1][w-1] = dungeon[h-1][w-1] >= 0 ? 0 : -dungeon[h-1][w-1];
    for (int i = h-2; i >= 0; i--) {
        base[i][w-1] = base[i+1][w-1] - dungeon[i][w-1];
        if (base[i][w-1] < 0) base[i][w-1] = 0;
        
    }
    for (int i = w-2; i >=0; i--) {
        base[h-1][i] = base[h-1][i+1] - dungeon[h-1][i];
        if (base[h-1][i] < 0) base[h-1][i] = 0;
    }
    
    for (int i = h-2; i >= 0; i--) {
        for (int j = w-2; j >= 0; j--) {
            base[i][j] = min(base[i+1][j], base[i][j+1]) - dungeon[i][j];
            if (base[i][j] < 0) base[i][j] = 0;
        }
    }
    
    return base[0][0] + 1;
}

