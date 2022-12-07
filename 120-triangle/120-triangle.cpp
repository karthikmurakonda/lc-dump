class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size()));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++){
            for(int j = 0; j <= i; j++){
                dp[i][j] = triangle[i][j];
                if(j != i && j != 0)
                dp[i][j] += min(dp[i-1][j-1],dp[i-1][j]);
                else if (j == 0)
                dp[i][j] += dp[i-1][0];
                else
                dp[i][j] += dp[i-1][j-1];
                // cout << dp[i][j] << endl;
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < triangle.size(); i++){
            ans = min(ans, dp[triangle.size()-1][i]);
        }
        return ans;
    }
};