class Solution {
public:
    int stoneGameII(vector<int>& piles) {
     int n = piles.size();

        // Step 1: suffix sum
        vector<int> suffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M]
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        function<int(int,int)> solve = [&](int i, int M) {
            if (i >= n) return 0;

            if (2 * M >= n - i)
                return suffix[i];

            if (dp[i][M] != 0)
                return dp[i][M];

            int best = 0;

            for (int X = 1; X <= 2 * M; X++) {
                best = max(best, suffix[i] - solve(i + X, max(M, X)));
            }

            return dp[i][M] = best;
        };

        return solve(0, 1);   
    }
};