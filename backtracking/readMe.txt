1.回溯法思想
  从初始状态出发，按照深度优先搜索的方式，
  根据产生子节点的条件约束，搜索问题的解
2.解题思路
  a.首先定义解空间：
    先确认解的组织形式，比如3元0-1背包问题的解形式可以定义为{x1,x2,x3} 其中xi = 0 表示加入解集合，否则不加入解集合。
    解空间就是所有可能解的集合 {0，0，0}  ..... {0,1,1}等等
    解空间可以形象的表式为一个n叉树，称解空间树

      /   \       边为x1为0或1
     /\   /\      边为x2为0或1
    /\/\ /\/\     边为x3为0或1
  b. 定义解空间的组织结构
    根据解空间树可以分为：子集树、排列数、m叉树
  c. 搜索解空间
    解空间越小，搜索越简单
    只求可行解： 定义约束函数    0-1背包问题
    要求最优解： 定义约束函数和界限函数  矩阵有没有路径
3.要点    
   func() {
    1、边界条件||退出条件
    2、
       如果满足约束条件 {
          func(t+1);
          回溯（长度减减、tag重置）
       }
       满足界限函数 {
          func(t+1);
       }
  }
    
4. 0-1背包问题：
  题目：物品不可切分的背包问题。
  思路：
    a. 解空间
      解空间可以定义为{x1,x2,x3……xn}， 显约束： xi = 0或1  0表示加入解集合，否则不加入解集合。
    b. 定义解空间的组织结构
      解空间树可以分为：{0，0，0}  ..... {0,1,1}   
      共有 2^3 = 个解， 即n个元素的组成的集合的所有子集的个数
    c. 搜索解空间
      约束条件： 加入物品的总重量>总容量。 那么杰克已不再搜索这些不满足条件的孩子的子节点。比如加入第二个物品超重，那么在树中的这一枝就可以剪掉了。
      界限函数： 所有的物品的价值总值最大，比如计算到某个节点，加上剩余所有没加入的都不会比目前最优值大，就可以结束搜索了。
  题解：
    1. 初始化，
      先判断是否需要搜索，即所有物品加入是否满足条件。
        
