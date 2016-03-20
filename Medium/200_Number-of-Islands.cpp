#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
    void dfs(vector<vector<char>>& grid, short **map, int cnt, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if (map[i][j] != 0 || grid[i][j] == '0') return;
        map[i][j] = cnt;
        dfs(grid, map, cnt, i+1, j);
        dfs(grid, map, cnt, i, j+1);
        dfs(grid, map, cnt, i-1, j);
        dfs(grid, map, cnt, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int y = grid.size();
        if (!y) return 0;
        int x = grid[0].size();
        if (!x) return 0;
        
        int cnt = 0; 
        short **map = new short*[y];
        for (int i = 0; i < y; i++) map[i] = new short[x];
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                map[i][j] = 0;
            }
        }
        
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (map[i][j] == 0 && grid[i][j] == '1') {
                  dfs(grid, map, ++cnt, i, j);
                }
            }
        }
        return cnt;
    }
int main(int argc, char const *argv[])
{
	vector<vector<char> > grid;
    vector<char> item;
    item.push_back('1');
    item.push_back('0');
    grid.push_back(item);
    cout << numIslands(grid) << endl;
	return 0;
}
