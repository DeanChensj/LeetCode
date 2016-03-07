#include <iostream>
#include <queue>
#include <vector>
using namespace std;

  int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        vector<queue<int> > Vector(16);
        queue<int> tmpQ;
        
        for(int i = 0; i < size; i++){
            int pos =  nums[i] & 0xF;
            Vector[pos].push(nums[i]);
        }
        
        for(int i = 1; i < 8; i++){
            for(int i = 0; i < 16; i++){
                while(Vector[i].size() != 0){
                    tmpQ.push(Vector[i].front());
                    Vector[i].pop();
                }
            }
            while(!tmpQ.empty()){
                int pos = (tmpQ.front() >> (i * 4)) & 0xF;
                Vector[pos].push(tmpQ.front());
                tmpQ.pop();
            }
        }
        
        for(int i = 0; i < 16; i++){
            while(Vector[i].size() != 0){
                tmpQ.push(Vector[i].front());
                Vector[i].pop();
            }
        }

        int tmp, next, max = 0, prev = tmpQ.front();
        
        while(!tmpQ.empty()){
            tmpQ.pop();
            next = tmpQ.front();
            tmp = next - prev;
            prev = next;
            if(tmp > max) max = tmp;
        }
        return max;
    }

int main(int argc, char const *argv[])
{
    vector<int> num;
    num.push_back(6);
    num.push_back(4);
    num.push_back(3);
    num.push_back(3);
	maximumGap(num);
	return 0;
}
