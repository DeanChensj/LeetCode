#include "../Header.h"

using namespace std;
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int> > graph(numCourses);
    for (auto bg: prerequisites) {
        graph[bg.second].insert(bg.first);
    }
    vector<int> inDegree(numCourses, 0);
    for (auto bg: graph) {
        for (auto ed : bg) inDegree[ed]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (!inDegree[i]) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inDegree[v] = -1;
        for (auto ed : graph[v]) {
            if (--inDegree[ed] == 0) q.push(ed);
        }
    }
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] != 0 && inDegree[i] != -1) return 0; 
    }
    return 1;
}

int main(int argc, char const *argv[])
{
	return 0;
}
