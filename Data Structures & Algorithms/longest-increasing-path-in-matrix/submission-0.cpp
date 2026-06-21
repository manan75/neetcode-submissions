class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool isValid(int i, int j, vector<vector<int>>& matrix) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return false;
        return true;
    }
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int count = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (isValid(x, y, matrix) && matrix[x][y] > matrix[i][j]) {
                count = max(count, 1 + solve(x, y, matrix, dp));
            }
        }
        return dp[i][j] = count;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int maxPath = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxPath = max(maxPath, solve(i, j, matrix, dp));
            }
        }
        return maxPath;
    }
};

