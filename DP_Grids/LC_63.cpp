class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        
        return helper(0,0,dp,obstacleGrid);
    }
    int helper( int p ,int q,vector<vector<int>> & dp,vector<vector<int>>&obstacleGrid){
        if(p>obstacleGrid.size()-1 ||q>obstacleGrid[0].size()-1) return 0;
        if(obstacleGrid[p][q]==1) return 0;
        if(p==obstacleGrid.size()-1 && q==obstacleGrid[0].size()-1 ) 
        {
        return 1 ;}
        if(dp[p][q]!=-1) return dp[p][q];
        return dp[p][q] = helper(p+1,q,dp,obstacleGrid)+ helper(p,q+1,dp,obstacleGrid);

    }
};
