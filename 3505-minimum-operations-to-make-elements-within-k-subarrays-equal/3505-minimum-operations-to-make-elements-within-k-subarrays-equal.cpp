
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto balance = [&]() {
            int need = (lo.size() + hi.size() + 1) / 2;

            while (lo.size() > need) {
                int v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() < need) {
                int v = *hi.begin();
                hi.erase(hi.begin());
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                hi.erase(hi.find(v));
                sumHi -= v;
            }
            balance();
        };

        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) remove(nums[i - x]);

            if (i >= x - 1) {
                long long med = *lo.rbegin();

                long long operations =
                    med * lo.size() - sumLo +
                    sumHi - med * hi.size();

                cost.push_back(operations);
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;

            for (int j = 1; j <= k; j++) {
                // Skip current element
                dp[i][j] = dp[i - 1][j];

                // Select a window of length x
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
