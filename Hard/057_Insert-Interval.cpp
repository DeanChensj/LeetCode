#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

static bool comp(const Interval &a,const Interval &b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        
        sort(intervals.begin(), intervals.end(), comp);
        queue<Interval> q;
       
        for (int i = 0; i < intervals.size(); i++) {
            q.push(intervals[i]);
        }
        vector<Interval> ans;
        for (int i = 0; i < intervals.size();i++) {
            Interval v = q.front();
            q.pop();
            Interval w = q.front();
            while (!q.empty() && v.end >= w.start) {
                i++;
                v.end = max(v.end, w.end);
                q.pop();
                w = q.front();
            }
            ans.push_back(v);
        }
        return ans;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }

int main(int argc, char const *argv[])
{
 
	return 0;
}
