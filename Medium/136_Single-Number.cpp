#include <iostream>
using namespace std;

int singleNumber(int A[], int n) {
    int a = A[0];
    for(int i = 1; i < n; i++){
        a ^= A[i];
    }
    return a;
}


int main(int argc, char const *argv[])
{
	int *A = new int[3];
    A[0] = 1;
    A[1] = 1;
    A[2] = 2;
    cout << singleNumber(num) << endl;
	return 0;
}
