class Solution {
public:
    using ll = long long;

    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();

        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        const ll NEG = -4e18;

        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, NEG));

        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;

        for (int t = 1; t <= k; t++) {
            ll best = NEG;

            for (int i = m; i <= n; i++) {
                best = max(best, dp[t - 1][i - m] - pre[i - m]);
                dp[t][i] = max(dp[t][i - 1], pre[i] + best);
            }
        }

        return dp[k][n];
    }
};