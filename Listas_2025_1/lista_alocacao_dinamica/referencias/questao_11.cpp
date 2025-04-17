class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        ++rowIndex; ++n;
        rowIndex = (rowIndex * (rowIndex + 1)) >> 1;
        auto solve = [&]() -> vector<int> {
            vector<vector<int>> dp(rowIndex + 1, vector<int>(n + 1));
            dp[1][1] = 1;
            if (n > 1) dp[2][2] = dp[3][2] = 1;
            int j = 0, counter = 0;
            if (n > 2) {
                j = 3;
                for(int i = 4;i <= rowIndex;++i) {
                    dp[i][j] = dp[i - j][j - 1] + dp[i - j + 1][j - 1];
                    if(++counter == j) {
                        ++j;
                        counter = 0;
                    }
                }
            }
            vector<int> ans;
            for(int i = rowIndex - n + 1;i <= rowIndex;++i) ans.push_back(dp[i][n]);
            return ans;
        };
        return solve();
    }
};
