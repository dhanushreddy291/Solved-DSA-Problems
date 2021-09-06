#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    int i = 0;
    vector<Interval> ans;
    
    if (newInterval.start > newInterval.end)
    {
        i = newInterval.end;
        newInterval.end = newInterval.start;
        newInterval.start = i;
        
        i = 0;
    }
    
    while (i < intervals.size())
    {
        if (intervals[i].start > newInterval.end)
        {
            ans.push_back(newInterval);
            
            while (i < intervals.size())
            {
                ans.push_back(intervals[i]);
                i++;
            }
        }
     
        else if (intervals[i].end < newInterval.start)
        ans.push_back(intervals[i]);
        
        else if (newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end)
        while (i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
        else if (intervals[i].start >= newInterval.start && newInterval.end >= intervals[i].end)
        {
            if (i == intervals.size() - 1)
            ans.push_back(newInterval);
        }
        
        else if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.start)
        newInterval.start = intervals[i].start;
        
        else if (intervals[i].start <= newInterval.end && intervals[i].end >= newInterval.end)
        {
            newInterval.end = intervals[i].end;
            ans.push_back(newInterval);
            
            i++;
            
            while (i < intervals.size())
            {
                ans.push_back(intervals[i]);
                i++;
            }
        }
        
        i++;
        
    }
    
    if (intervals.size() == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    
    if (intervals[intervals.size() - 1].end < newInterval.start)
    ans.push_back(newInterval);
    
    return ans;
    
}

int main()
{

	return 0;
}