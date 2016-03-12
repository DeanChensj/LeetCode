#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else 
            i++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > matrix;
	vector<int> num;
    num.push_back(1);
    num.push_back(1);
    matrix.push_back(num);
    cout << searchMatrix(matrix, 1) << endl;
	return 0;
}
