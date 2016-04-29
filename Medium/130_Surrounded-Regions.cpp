#include "../Header.h"

using namespace std;
void helper(vector<vector<char> >& board, int i, int j) {
    board[i][j] = '1';
    if (i > 1 && board[i-1][j] == 'O') helper(board, i-1, j);
    if (i < board.size()-1 && board[i+1][j] == 'O') helper(board, i+1, j);
    if (j > 1 && board[i][j-1] == 'O') helper(board, i, j-1);
    if (j < board[0].size()-1 && board[i][j+1] == 'O') helper(board, i, j+1);
}

void solve(vector<vector<char>>& board) {
    int h = board.size(), w = h ? board[0].size() : 0;
    for (int j = 0; j < w; j++) {
        if (board[0][j] == 'O') helper(board, 0, j);
        if (board[h-1][j] == 'O') helper(board, h-1, j);
    }
    for (int i = 1; i < h-1; i++) {
        if (board[i][0] == 'O') helper(board, i, 0);
        if (board[i][w-1] == 'O') helper(board, i, w-1);
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '1') board[i][j] = 'O';
            else board[i][j] = 'X';
        }
    }
}
int main(int argc, char const *argv[])
{
	
	return 0;
}
