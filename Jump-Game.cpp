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
