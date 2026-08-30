class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mini, maxi);
        int right = max(mini, maxi);

        // Case 1: dono left se
        int case1 = right + 1;

        // Case 2: dono right se
        int case2 = n - left;

        // Case 3: left se ek, right se ek
        int case3 = (left + 1) + (n - right);

        return min({case1, case2, case3});
    }
};