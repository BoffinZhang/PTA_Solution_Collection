# PTA_Solution_Collection
Solutions for PTA advanced trainning problem set.

## 1010 Radix
寻找最小的基数，使得两个数相等
二分搜索，需要注意各种边界情况。

## 1011 World Cup Betting
选出每行的最大值，对应字母，输出乘积即可

## 1012 The Best Rank
重写cmp函数，分3种情况排序，注意分数相同对排序的影响，最终输出答案即可

## 1013 Battle Over Cities
找出一张图中，去除某个节点后的强连通分量数
用dfs做连通分量标记，计数即可
注意每次询问之后，要重置vis数组（重置访问标记）

## 1014 Waiting in Line
利用优先队列和队列进行模拟
维护一条优先队列，用于处理全部的“用户交易”，进行处理的时间调度，重载小于号，偏序关系：结束时间-窗口ID
维护N个队列，处理每个窗口前的交易
每处理掉一个用户，就有一个新用户跨过黄线进入队列尾，再将队首移入优先队列
