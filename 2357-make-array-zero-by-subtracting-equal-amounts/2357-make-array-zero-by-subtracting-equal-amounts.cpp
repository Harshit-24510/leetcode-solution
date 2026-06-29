class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int x = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                x = min(x, nums[i]);
            }
        }

        while (x != INT_MAX) {
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    nums[i] -= x;
                }
            }

            count++;

            x = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    x = min(x, nums[i]);
                }
            }
        }

        return count;
    }
};