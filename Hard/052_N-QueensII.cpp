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

void nQueensHelper(int n, int pt, int *table, int &result){
	if (pt == n) {
		result++;
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

int totalNQueens(int n) {
    int *table = new int[n];
 	int result = 0;

    for (int i = 0; i < n; ++i) {
    	table[0] = i;
    	nQueensHelper(n, 1, table, result);
    }
    cout << "n = " <<  n << "\nresult = " << result << endl; 
    return result;
}

int main(int argc, char const *argv[])
{
	totalNQueens(13);   
	return 0;
}