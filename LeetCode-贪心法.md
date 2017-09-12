---
title: LeetCode-贪心法
date: 2017-08-26 14:55:11
categories: LeeCode
tags: 
- LeetCode
- 贪心法
- 算法
copyright: true
---
  贪心算法（又称贪婪算法）是指，在对问题求解时，总是做出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，他所做出的是在某种意义上的局部最优解。
贪心算法不是对所有问题都能得到整体最优解，关键是贪心策略的选择，选择的贪心策略必须具备无后效性，即某个状态以前的过程不会影响以后的状态，只与当前状态有关。
<!--more-->
# Jump Game 
## Description
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 
## 思路
### 贪心法
先将A[i]所跳的最大位置找到，再从这个位置依次往A[i+1]处遍历，在这期间找到第二个最大的位置．再重复刚才的im过程，在这个中间可以判断是否能够跳到最后。
### 动态规划
如果能够达到最高层，则说明每一步都能够到达．设状态为f[i]，表示从0层开始出发，走到A[i]时剩余的最大步数，则状态转移方程为：f[i]=max(f[i-1]，A[i-1])-1．如果f[i]<0，表示走不到位置i.
## C++实现
```c++
class Solution {
    //贪心法，算法复杂度O(n)
public:
    bool canJump(vector<int>& nums) {
        int reach = 0; //最右能跳到那里
        for(int i=0;i<=reach&&reach<=nums.size();i++){
            reach=max(reach,i+nums[i]);
        }
        return reach>=nums.size()-1;
    }
};


class Solution {
    //动态规划
public:
    bool canJump(vector<int>& nums) {
       vector<int> f(nums.size(),0);
       for(int i=1;i<nums.size();i++){
           f[i]=max(f[i-1],A[i-1])-1;
           if(f[i]<0) return false;
       }
        return true;
    }
};
```

# Jump Game 2
## Description
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
## 思路
### 贪心法
依旧贪心去推，贪心的规则就是在能够到达的范围之内，从中选择一个能够到达比当前范围最远距离的点，更新步数，和更新最远到达的范围。
这样的策略就是竭力要走的更远。
### 动态规划法
首先想到动态规划。数组H[i ]， H[i]表示index从0到i的最少跳数。若H[i] = m，那么试图去更新i之后的m个位置的最少跳数。
可是，需要空间复杂度O(N)。
```c
//贪心算法
class Solution {
public:
    int jump(int A[], int n) {
        int maxx=0,temp=0,num=0;
        for(int i=0;i<n;)
        {
            if(temp>=n-1)break;
            while(i<=temp)
            {
                maxx=max(maxx,i+A[i]);
                ++i;
            }
            num++;
            temp=maxx;            
        }
        return num;
        
    }
};

//动态规划
int jump(int A[], int n) {
    if(n < 2)
        return 0;
    int H[n];
    memset(H, 0, sizeof(H));
    
    H[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int m = A[i];
        if(i + m >= n-1)
            return H[i] + 1;
        
        for(int j=1;j<=m;j++)
        {
            if(H[i+j] == 0 || H[i+j] > H[i] + 1)
                H[i+j] = H[i] + 1;
        }
    }
    return H[n-1];
}
```
# Best Time to Buy and Sell Stock 
## Description
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:

Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:

Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
## 思路
只需要找出最大的差值即可，即 max(prices[j] – prices[i]) ，i < j。一次遍历即可，在遍历的时间用遍历low记录 prices[o….i] 中的最小值，就是当前为止的最低售价，时间复杂度为 O(n)。 
## C++实现
```c++
 int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        int cur_min=prices[0];
        int profit=0;
       for(int i=1;i<prices.size();i++){
           cur_min=min(cur_min,prices[i]);
           profit=max(profit,prices[i]-cur_min);
       }
        return profit;
    }
    ```

# longest substring without repeating
## Description
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
## 思路
    假设子串里含有重复字符，则父串一定含有重复字符，单个子问题就可以决定父问题，因此可以用贪心法。跟动规不同，动规里，单个子问题只能影响父问题，不足以决定父问题。

从左往右扫描，当遇到重复字母时，以上一个重复字母的{index+1}，作为新的搜索起始位置，直到最后一个字母，复杂度是O(n)。
## C++实现
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ASCII_MAX=128;
        int start=0;//记录当前子串的起始位置
        int last[ASCII_MAX];//记录字符上次出现过的位置
        fill(last,last+ASCII_MAX,-1);//0也是位置，因此初始化为１
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            if(last[s[i]]>=start){
                maxlen=max(i-start,maxlen);
                start=last[s[i]]+1;
            }
            last[s[i]]=i;
        }
        return max((int)s.size()-start,maxlen);//start之后到字符串结束都没有重复字符
    }
};   
```
# Container with most water
## Description
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2. 
## 思路
每个容器的面积，取决于最短的木板;
用两个指针从两端开始向中间靠拢，如果左端线段短于右端，那么左端右移，反之右端左移，知道左右两端移到中间重合，记录这个过程中每一次组成木桶的容积，返回其中最大的。(合理性解释：当左端线段L小于右端线段R时，我们把L右移，这时舍弃的是L与右端其他线段（R-1, R-2, ...）组成的木桶，这些木桶是没必要判断的，因为这些木桶的容积肯定都没有L和R组成的木桶容积大。)
## C++实现
```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        int result=0;
        while(right>left){
            area=min(height[left],height[right])*(right-left);
            result=max(result,area);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};
```