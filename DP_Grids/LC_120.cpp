class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
    //     vector<vector<int> > dp(n, vector<int>(n, 0));

    // // Initialize the bottom row of dp with the values from the triangle
    // for (int j = 0; j < n; j++) {
    //     dp[n - 1][j] = triangle[n - 1][j];
    // }

    // // Iterate through the triangle rows in reverse order
    // for (int i = n - 2; i >= 0; i--) {
    //     for (int j = i; j >= 0; j--) {
    //         // Calculate the minimum path sum for the current cell
    //         int down = triangle[i][j] + dp[i + 1][j];
    //         int diagonal = triangle[i][j] + dp[i + 1][j + 1];

    //         // Store the minimum of the two possible paths in dp
    //         dp[i][j] = min(down, diagonal);
    //     }
    // }

    vector<vector<int>> dp(n,vector<int>(n,0));
    for (int j =n-1;j>=0;j--){
        dp[n-1][j] = triangle[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = dp[i+1][j]+triangle[i][j];
            int diag = dp[i+1][j+1]+triangle[i][j];
                dp[i][j] = min (down, diag); 
        }
    }
    return dp[0][0];

    // The top-left cell of dp now contains the minimum path sum
    // return dp[0][0];
    
    //     int n = triangle.size();
    //     vector<vector<int> > dp(n, vector<int>(n, -1));
    // // Call the recursive function to find the minimum path sum
    // return minimumPathSumUtil(0, 0, triangle, n, dp);
    }

   int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle, int n,
                       vector<vector<int> > &dp) {
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If we're at the bottom row, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];

    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}
};
