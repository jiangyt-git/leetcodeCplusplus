1. 分治法解决的问题满足以下3个条件：
  a. 原问题可以分割成若干个规模较小的子问题
  b. 子问题相互独立
  c. 子问题可以合并为原问题的解
2. 分治法解决问题的步骤：
  a. 分解成子问题  --》  解决子问题  --》 合并子问题的结果
  b. 因为在分治中，子问题的形式相同、解决方法也相同，所以可以用《--递归法--》来解决问题。
3. 例子
  a. 二分搜索
    思想：将序列分成规模大致相等的两部分，然后取中间值与待寻找值x比较。相等则找到退出，x小于中间值则在前半部分查找，即在前半部分分解和治理问题。x大于中间值则在后半部分查找。
    注意：注意在取中位数的时候，不要超出数值界限， mid = start + (end-start)/2;
    代码：
      int BinarySearch (int arr[], int n, int target) {
        int start = 0;
        int end = n-1;
        while (start <= end) {
          int mid = start + (end - start)/2;
          if (arr[mid] == target) {
            return mid;
          } else if (arr[mid] < target) {
            start = mid + 1;
          } else {
            end = mid -1;
          }
          return -1;
        }
      }
      但如果使用递归法，则需要额外的空间，因为递归时会将调用过程压入栈中。比如，问题原规模为n,第一次分为 2个n/2规模的问题，但每次只执行其中之一，直到问题的规模为1，即
        n/ 2^x = 1   解得x = logn
        即递归版二分法空间复杂度为 O(longn)
  b. 归并排序
    思路：
      分解： 将序列分成两个规模相似的子序列
      治理： 对每个子问题进行合并排序
      合并： 将两个有序子序列合并起来
    注意： 归并时需要辅助数组， 分解易合并难
    代码： 
      void mergeSort(int arr[], int low, int high) {
        if (low >= high) {
          return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
      }
      void merge(int arr[], int low, int mid, int high) {
        int * tmp = new int[high-low+1];
        int i = low;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= high) {
          if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
          } else {
            tmp[k++] = arr[j++];
          }
        }
        while (i <= mid) {
          tmp[k++] = arr[i++];
        }
        while (j <= high) {
          tmp[k++] = arr[j++];
        }
        // 将排好序的数组复制到arr中
        for (i = low, k = 0; i <= high; i++) {
          arr[i] = tmp[k++];
        }
        delete tmp[];
      }
  c.快速排序
    思路：
      分解：从序列中选取一个作为基准，然后将序列分为两个子序列，左边的比基准小，右边的比基准大
      治理：对两个子序列进行快排
      合并：将两个子序列合在一起组成最终序列
    注意： 原地排序，分解难，合并容易  
