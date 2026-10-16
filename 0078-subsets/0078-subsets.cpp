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
        

        subset(i+1, nums, ans, v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        subset(0, nums, ans, v);

        return ans;
    }
};