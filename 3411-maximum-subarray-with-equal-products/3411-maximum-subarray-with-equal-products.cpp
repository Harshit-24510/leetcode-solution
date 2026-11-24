class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1, l = 1;
            int g = 0;

            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                l = l / gcd(l, (long long)nums[j]) * nums[j];

               
                if (prod > LLONG_MAX / nums[j])
                    break;

                prod *= nums[j];

                if (prod == 1LL * g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};