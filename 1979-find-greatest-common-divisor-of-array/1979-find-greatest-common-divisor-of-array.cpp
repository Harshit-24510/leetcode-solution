class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        int res = 1;

        for (int i = 1; i <= mini; i++) {
            if (mini % i == 0 && maxi % i == 0) {
                res = i;   
            }
        }

        return res;
    }
};