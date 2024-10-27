class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        
        // 建立 DP 表格，用來存儲以每個位置為右下角的最大正方形邊長
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        // 如果是矩陣的第一列或第一行，只能形成邊長為 1 的正方形
                        dp[i][j] = 1;
                    } else {
                        // 以鄰近的 DP 值中最小的為基礎，加上 1
                        dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    }
                    // 將 dp[i][j] 加入總數
                    ans += dp[i][j];
                }
            }
        }
        
        return ans;
    }
};
