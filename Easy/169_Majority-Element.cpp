#include <iostream>
#include <vector>
#include <string>
using namespace std;
    int majorityElement(vector<int> &num) {
        int element = num[0], cnt = 1;
        for (int i = 1; i < num.size(); i++) {
            (num[i] == element) ? cnt++ : cnt--;
            if (cnt == 0) {
                element = num[i];
                cnt = 1;
            }
        }
        return element;
    }


int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(6);
    num.push_back(0);
    num.push_back(3);
    num.push_back(3);
	cout << majorityElement(num);   
	return 0;
}