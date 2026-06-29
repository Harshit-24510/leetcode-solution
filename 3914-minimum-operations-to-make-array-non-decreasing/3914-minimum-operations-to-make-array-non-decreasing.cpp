class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                ans += 1LL * (nums[i - 1] - nums[i]);
            }
        }

        return ans;
    }
};