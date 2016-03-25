#include "../Header.h"

using namespace std;
int candy(vector<int>& ratings) {
    int n = ratings.size(), candies = 0, altitude = 1;
    // 建图，if ratings[i-1] < ratings[i]  i-1 指向i 
    vector<unordered_set<int> > graph(n);
    for (int i = 0; i < n-1; i++)  if (ratings[i] < ratings[i+1]) graph[i].insert(i+1);
    for (int i = 1; i < n; i++)  if (ratings[i] < ratings[i-1]) graph[i].insert(i-1);
    // 计算入度
    vector<int> inDegree(n, 0);
    for (auto bg: graph) {
        for (auto ed : bg) inDegree[ed]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!inDegree[i]) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int cnt = 0;
        vector<int> vec;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cnt++;
            inDegree[v] = -1;
            vec.push_back(v);
        }
        
        for (int i = 0; i < vec.size(); i++) {
            for (auto ed : graph[vec[i]]) {
                if (--inDegree[ed] == 0)
                    q.push(ed);
            }
        }
        
        // for (auto i : inDegree) printf("%d ", i);
        // cout << endl;
        candies += cnt * altitude;
        // printf("%d man has %d candies, and now we got %d candies\n",cnt, altitude, candies);
        altitude++;
    }
    
    return candies;
}

int main(int argc, char const *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(2);
    num.push_back(1);
	cout << candy(num) << endl;
	return 0;
}
