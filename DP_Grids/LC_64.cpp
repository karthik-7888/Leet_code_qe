class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        
        return helper(0,0,dp,grid);
    }
    int helper( int p ,int q,vector<vector<int>> & dp,vector<vector<int>>&obstacleGrid){
        if(p>obstacleGrid.size()-1 ||q>obstacleGrid[0].size()-1) return INT_MAX;
        // if(obstacleGrid[p][q]==1) return 0;
        if(p==obstacleGrid.size()-1 && q==obstacleGrid[0].size()-1 ) 
        {
        return obstacleGrid[p][q] ;}
        if(dp[p][q]!=-1) return dp[p][q];
        return dp[p][q] = obstacleGrid[p][q]+ min(helper(p+1,q,dp,obstacleGrid),helper(p,q+1,dp,obstacleGrid));

    }
};
