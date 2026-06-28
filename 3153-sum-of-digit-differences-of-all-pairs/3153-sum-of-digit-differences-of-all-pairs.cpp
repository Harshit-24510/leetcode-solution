using ll = long long;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int len = to_string(nums[0]).size();
        ll ans = 0;
        int place = 1;

        for (int pos = 0; pos < len; pos++) {
            vector<int> cnt(10, 0);

            for (int i = 0; i < nums.size(); i++) {
                int digit = (nums[i] / place) % 10;
                ans += i - cnt[digit];
                cnt[digit]++;
            }

            place *= 10;
        }

        return ans;
    }
};