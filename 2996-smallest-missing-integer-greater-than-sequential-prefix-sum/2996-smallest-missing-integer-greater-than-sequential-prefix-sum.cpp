class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int sum = nums[0];
        int maxsum = INT_MIN;

        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] == nums[i] + 1) {
                sum += nums[i + 1];
            }
            else {
                break;
            }
        }

        maxsum = sum;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(maxsum == nums[i]) {
                maxsum++;
                i = -1;
            }
        }

        return maxsum;
    }
};