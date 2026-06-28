using ll = long long;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int len = to_string(nums[0]).size();
        ll ans = 0;

        for (int pos = 0; pos < len; pos++) {
            vector<int> cnt(10, 0);

            for (int i = 0; i < n; i++) {
                int digit = (nums[i] / (int)pow(10, pos)) % 10;
                ans += i - cnt[digit];
                cnt[digit]++;
            }
        }

        return ans;
    }
};