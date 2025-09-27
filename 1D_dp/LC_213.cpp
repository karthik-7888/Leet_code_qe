class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        if (nums.size() == 1) return nums[0];
       return max(helper(nums,nums.size()-2,dp1,0),helper(nums,nums.size()-1,dp2,1)); 
    }

    int helper(vector<int>&nums,int n,vector<int>&dp,int start){
        if(n==start) return nums[n];
        if(start>n) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n] = max(helper(nums,n-1,dp,start),nums[n]+helper(nums,n-2,dp,start));
        return dp[n];
    }
};
