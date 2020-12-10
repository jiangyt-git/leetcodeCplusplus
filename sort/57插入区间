/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

iterator insert( iterator pos, const T& value );
所以位置是 vec.begin() 或者vec.begin() + n


思路：
首先计算新区间之前的区间
计算融合之后的新区间
计算新区间之后的区间
*/
#include <algorithm>
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> ret;
      if (intervals.empty()) {
          ret.push_back(newInterval);
          return ret;
      }
      int cur = 0;	
      int i = 0 ;
      for (; i <intervals.size(); i++) {
        if (newInterval[0] > intervals[i][1]) {
          ret.push_back(intervals.at(i));
        } else {
          break;
        }
      }
      cur = i;
      // 计算新区间
      int start = newInterval[0];
      int end  = newInterval[1];
      int j = cur;       
      for (; j < intervals.size(); j++) {
          if (intervals[j][0] > end) {
              // 不融合
              break;
          }
          // 否则融合
          start = std::min(start, intervals[j][0]);
          end = std::max(end,intervals[j][1]);
      }
      ret.push_back({start,end});		

      // 新区间之后的
      if (j < intervals.size()) {
        ret.insert(ret.end(),intervals.begin()+j,intervals.end());
      }
      return ret;
    }
};
