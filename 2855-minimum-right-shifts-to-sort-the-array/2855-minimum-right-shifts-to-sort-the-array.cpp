class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int idx = -1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                cnt++;
                idx = i;
            }
        }

        if (cnt == 0)
            return 0;

        if (cnt > 1)
            return -1;

        if (nums[n - 1] > nums[0])
            return -1;

        return n - idx - 1;
    }
};