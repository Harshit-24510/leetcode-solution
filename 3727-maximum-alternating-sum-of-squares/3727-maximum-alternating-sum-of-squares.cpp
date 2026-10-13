class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int &x : nums)
            x = abs(x);

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int pos = (n + 1) / 2;
        int neg = n - pos;

        long long ans = 0;

        for (int i = n - 1; i >= neg; i--)
            ans += 1LL * nums[i] * nums[i];

        for (int i = 0; i < neg; i++)
            ans -= 1LL * nums[i] * nums[i];

        return ans;
    }
};