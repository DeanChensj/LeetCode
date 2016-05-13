#include "../Header.h"

using namespace std;
class NumMatrix {
private:
    int **dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int h = matrix.size(), w = h ? matrix[0].size() : 0;
        if (!w) return;
        dp = new int* [h];
      	for (int i = 0; i < h; i++) dp[i] = new int[w];
        dp[0][0] = matrix[0][0];
        for (int i = 1; i < w; i++) dp[0][i] = dp[0][i-1] + matrix[0][i];
        for (int i = 1; i < h; i++) dp[i][0] = dp[i-1][0] + matrix[i][0];
        for (int i = 1; i < h; i++) {
            for (int j = 1; j < w; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2][col2] - (col1 ? dp[row2][col1-1] : 0) - (row1 ? dp[row1-1][col2] : 0) + (row1 && col1 ? dp[row1-1][col1-1] : 0);
    }
};
int main(int argc, char const *argv[])
{

	return 0;
}
