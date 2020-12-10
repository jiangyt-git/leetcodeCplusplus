class Solution {
/*
给出一个区间的集合，请合并所有重叠的区间。
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

注意：
Input: [[1,3],[1，2]]
Output: [[1,3]]

思路：
先排序，再合并。
*/
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [] (const vector<int> &a,
            const vector<int> &b) {
            return  a[0] < b[0];
        });
        vector<vector<int>> ret; 
        for (int i = 0; i < intervals.size() ; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i+1;
            for (; j < intervals.size(); j++) {
                if (intervals[j][0] > end ) {
                    break;
                } else {
                    if (end < intervals [j][1]) {
					  end = intervals [j][1];
				    }                       
                }
            }
            i = j-1;
            ret.push_back({start, end});
        }
        return ret; 
    }
};
