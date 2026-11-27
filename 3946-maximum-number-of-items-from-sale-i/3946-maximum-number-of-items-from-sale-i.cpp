class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;

        vector<int> freq(MAXF + 1, 0);

        for (auto &it : items)
            freq[it[0]]++;

        vector<int> multiples(MAXF + 1, 0);

        for (int f = 1; f <= MAXF; f++) {
            for (int m = f; m <= MAXF; m += f) {
                multiples[f] += freq[m];
            }
        }

        vector<int> dp(budget + 1, 0);

        for (auto &it : items) {
            int factor = it[0];
            int price  = it[1];

            int bonus = multiples[factor] - 1;

            vector<int> ndp = dp;

            for (int b = budget; b >= price; b--) {
                ndp[b] = max(
                    ndp[b],
                    dp[b - price] + 1 + bonus
                );
            }

            for (int b = price; b <= budget; b++) {
                ndp[b] = max(
                    ndp[b],
                    ndp[b - price] + 1
                );
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};