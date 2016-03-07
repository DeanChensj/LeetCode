#include <iostream>
#include <vector>
#include <string>
using namespace std;
     void moveZeroes(vector<int>& nums) {
        int cnt = 0, i = 0, size = nums.size();
        for(; i < size; i++) {
            while(i + cnt < size && nums[i + cnt] == 0)
                cnt++;
            
            if(i + cnt < size) {
               nums[i] = nums[i+cnt];
            } else {
                break;
            }
        }
        for(; i < size; i++){
            nums[i] = 0;
        }
    }


int main(int argc, char const *argv[])
{
	vector<int> num;
    num.push_back(6);
    num.push_back(0);
    num.push_back(3);
    num.push_back(3);
	moveZeroes(num);   
	return 0;
}