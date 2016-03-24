#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool macro(vector<vector<char>>& board, string word, bool **isVisited, stack<pair<int, int> > &S, int cnt, int x, int y) {
        bool flag = 0;
        if (board[x][y] == word[cnt]) {
            // printf("board[%d][%d] = word[%d] = %c\n", x, y, cnt, word[cnt]);
            isVisited[x][y] = 1;
            S.push(make_pair(x, y));
            flag = helper(board, word, cnt+1, isVisited, S);
            isVisited[x][y] = 0;
            S.pop();
        }
        return flag;
    }
    
    bool helper(vector<vector<char>>& board, string word, int cnt, bool **isVisited, stack<pair<int, int> > &S) {
        pair<int, int> p = S.top();
        int i(p.first), j(p.second);
        if (cnt == word.size()) return 1;
        
        if (0) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    cout << isVisited[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        
        bool flag = 0;
        if (i+1 < board.size() && !isVisited[i+1][j]) flag += macro(board, word, isVisited, S, cnt, i+1, j);
        if (flag) return 1;
        if (i-1 >= 0 && !isVisited[i-1][j]) flag += macro(board, word, isVisited, S, cnt, i-1, j);
        if (flag) return 1;
        if (j+1 < board[0].size() && !isVisited[i][j+1]) flag += macro(board, word, isVisited, S, cnt, i, j+1);
        if (flag) return 1;
        if (j-1 >= 0 && !isVisited[i][j-1]) flag += macro(board, word, isVisited, S, cnt, i, j-1);
        return flag;   
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        bool flag = 0;
        int y = board.size();
        if (!y) return flag;
        int x = board[0].size();
        if (!x) return flag;
        if (x * y < word.length()) return flag;
        
        int cnt = 0;
        bool **isVisited = new bool*[y];
        for (int i = 0; i < y; i++) isVisited[i] = new bool[x];
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                isVisited[i][j] = 0;
            }
        }
        
        stack<pair<int, int> > S;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (board[i][j] == word[cnt]) {
                    // printf("board[%d][%d] = word[%d] = %c\n", i, j, cnt, word[cnt]);
                    isVisited[i][j] = 1;
                    S.push(make_pair(i, j));
                    flag += helper(board, word, cnt+1, isVisited, S);
                    isVisited[i][j] = 0;
                    S.pop();
                }
                if (flag) return flag;
            }
        }
        return flag;
    }
};
