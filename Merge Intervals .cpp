// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
//  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 

// Example 2:
//  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16]. 

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int sz = intervals.size();
        int position = sz;
        for (int i = 0; i < sz; ++i)
        {
        	if (newInterval.start < intervals[i].start)
        	{
        		position = i;
        		break;
        	}
        }
        
        while (k + 1 < sz)
		{
			if (intervals[k].end >= intervals[k + 1].start) {
				if (intervals[k].end < intervals[k + 1].end)
				{
					intervals[k].end = intervals[k + 1].end;
				}
				intervals.erase(intervals.begin() + k + 1);
				sz = intervals.size();
			}
			else
			{
				k++;
			}
		}
        
    }
};