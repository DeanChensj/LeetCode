#include <iostream>
#include <vector>
#include <string>
using namespace std;
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = (C - A) * (D - B);
        int b = (G - E) * (H - F);
        int c;
        
        if (C < E || D < F || A > G || B > H) c = 0;
        else {
            int x = min(C, G) - max(A, E);
            int y = min(D, H) - max(B, F);
            c = x * y;
        }
        
        return a + b - c;
    }
int main(int argc, char const *argv[])
{
	cout << computeArea(-2, -2, 2, 2, -2, -2, 2, 2) << endl;
	return 0;
}