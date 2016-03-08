#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(!nums.size()) return res;
        
        int bg(0), strike(0);
        while (bg + strike < nums.size()) {
            strike++;
            int ed = bg + strike;
            if (ed == nums.size() || nums[bg] != nums[ed] - strike) {
                ed--;
                
                string s = "";
                char *c = new char[100];
                if (bg == ed) {
                    sprintf(c, "%d", nums[bg]);
                } else {
                    sprintf(c, "%d->%d", nums[bg], nums[ed]);
                }
               s += c;
               res.push_back(s);
               
               bg += strike;
               strike = 0;
            } 
         
        }
        return res;
    }


int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(0);
    num.push_back(2);
    num.push_back(3);
    num.push_back(5);

    vector<string> a = summaryRanges(num);
    for (vector<string>::iterator i = a.begin(); i != a.end(); ++i) {
        cout << *i << endl;
    }
	return 0;
}