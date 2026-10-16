class Solution {
public:
    void subset(int i, vector<int>& nums,vector<vector<int>>& ans, vector<int>& v) {

        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }

        // Pick
        v.push_back(nums[i]);
        subset(i + 1, nums, ans, v);
        v.pop_back();

        // Not pick
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }

        subset(j, nums, ans, v);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        subset(0, nums, ans, v);

        return ans;
    }
};