class Solution {
public:
    int maximumLength(vector<int>& nums) {
        const int maxNum = *max_element(nums.begin(), nums.end());
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = cnt.count(1) ? cnt[1] - (cnt[1] % 2 == 0 ? 1 : 0) : 1;

        for (auto& [base, freq] : cnt) {
            if (base == 1) continue;

            int length = 0;
            long long x = base;

            while (x <= maxNum && cnt.count(x) && cnt[x] >= 2) {
                length += 2;
                x *= x;
            }

            length += (cnt.count(x) && cnt[x] >= 1) ? 1 : -1;
            ans = max(ans, length);
        }

        return ans;
    }
};