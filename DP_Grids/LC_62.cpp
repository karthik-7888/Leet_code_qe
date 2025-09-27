class Solution {
public:
    int count = 0;
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return helper(m-1,n-1,0,0,dp);
    }
    int helper(int m,int n , int p ,int q,vector<vector<int>> & dp){
        if(p==m && q==n ) 
        {
        return 1 ;}
        if(p>m ||q>n) return 0;
        if(dp[p][q]!=-1) return dp[p][q];
        return dp[p][q] = helper(m,n,p+1,q,dp)+ helper(m,n,p,q+1,dp);

    }
};
