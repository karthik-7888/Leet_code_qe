class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
       return helper(nums,nums.size()-1,dp);
    }

    int helper(vector<int>&nums,int n,vector<int>&dp){
        if(n==0) return nums[0];
        if(n==-1) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n] = max(helper(nums,n-1,dp),nums[n]+helper(nums,n-2,dp));
        return dp[n];
    }
};
