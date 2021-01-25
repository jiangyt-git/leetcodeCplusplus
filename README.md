# leetcodeCplusplus
code by c++

注意1.贪心算法与动态规划的区别
共同点：两者都具有最优子结构性质
不同点：
  1) 动态规划算法中，每步所做的选择往往依赖于相关子问题的解，因而只有在解出相关子问题时才能做出选择。而贪心算法，仅在当前状态下做出最好选择，即局部最优选择，然后再去解做出这个选择后产生的相应的子问题。
  2) 动态规划算法通常以自底向上的方式解各子问题，而贪心算法则通常自顶向下的方式进行。
  
注意2.分治法与动态规划：
  1) 分治算法是将原问题分解为若干子问题，然后再合并子问题，所以是自顶向下的思考问题。
  2) 动态规划是将原问题分解为若干子问题，然后先从最小的问题解决，把结果存储在表格中，求解大的子问题时就直接查表，避免重复计算。
  分治法也是将问题分解成多个相同解法的子问题，但当子问题很多是相同的时候，就可以使用动态规划，提高效率。  
重点：
  二分框架：
    符合在有序数组中搜索给定的某个目标值的索引，即连续的空间线性搜索，这就是二分查找可以发挥作用的标志。
    for (int i = 0; i < n; i++)
      if (isOK(i))
          return ans;
          
    模板
      int binary_search(int[] nums, int target) {
      int left = 0, right = nums.length - 1; 
      while(left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1; 
          } else if(nums[mid] == target) {
              // 直接返回
              return mid;
          }
      }
      // 直接返回
      return -1;
    }

    int left_bound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                // 别返回，锁定左侧边界
                right = mid - 1;
            }
        }
        // 最后要检查 left 越界的情况
        if (left >= nums.length || nums[left] != target)
            return -1;
        return left;
    }


    int right_bound(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                // 别返回，锁定右侧边界
                left = mid + 1;
            }
        }
        // 最后要检查 right 越界的情况
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }

1.贪心
  冒泡、背包、单源最短路径Dijkstra、区间排序、最小生成树Prim
  
2.分治
  二分、归并、快排
  
