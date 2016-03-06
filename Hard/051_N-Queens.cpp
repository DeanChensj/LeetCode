#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool judger(int n, int pt, int *table){
	for (int i = 0; i < pt; ++i) {
		if (table[i] == table[pt] || (table[i] + pt == table[pt] + i) \
		 || (table[i] - pt == table[pt] - i)) {
			return false;
		}
	}
	return true;
}

void nQueensHelper(int n, int pt, int *table, vector<vector<string> > &result){
	if (pt == n) {
		vector<string> item;
		for (int i = 0; i < n; ++i) {
			string s(n, '.');
			s[table[i]] = 'Q';
			item.push_back(s);
		}
		result.push_back(item);
		return;
	}

	for (int i = 0; i < n; ++i) {
		table[pt] = i;
		if (judger(n, pt, table)) {
			nQueensHelper(n, pt+1, table, result);
		}
	}
	return;
}

vector<vector<string> > solveNQueens(int n) {
    int *table = new int[n];
    vector<vector<string> > result; 

    for (int i = 0; i < n; ++i) {
    	table[0] = i;
    	nQueensHelper(n, 1, table, result);
    }

    return result;
}

int main(int argc, char const *argv[])
{
	solveNQueens(4);   
	return 0;
}