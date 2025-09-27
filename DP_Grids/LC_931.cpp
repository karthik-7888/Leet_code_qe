class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i =0;i<n;i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i =n-2 ;i>=0;i--){
            for(int j = 0;j<n;j++){
                if(j==0){
                    int down = matrix[i][j] + dp[i+1][j];
                    int right = matrix[i][j]+dp[i+1][j+1];
                    dp[i][j] = min(down,right);
                }
                else if(j==n-1){
                    int down = matrix[i][j] + dp[i+1][j];
                    int left = matrix[i][j]+dp[i+1][j-1];
                    dp[i][j] = min(down,left);
                }
                else{
                    int down = matrix[i][j] + dp[i+1][j];
                    int left = matrix[i][j]+dp[i+1][j-1];
                    int right = matrix[i][j]+dp[i+1][j+1];
                    int k = min(down,left);
                    dp[i][j] = min(k,right);

                }

            }

        }
        int ans = INT_MAX;
        for(int j = 0;j<n;j++){
            ans  = min(ans,dp[0][j]);
        }
        return ans;
    }
};
