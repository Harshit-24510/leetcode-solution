
class Solution {
public:
    void recurse(vector<int>& candidates, int target, int i,vector<int>& v, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (i == candidates.size() || target < 0) {
            return;
        }
        //take
        v.push_back(candidates[i]);
        recurse(candidates, target - candidates[i], i, v, ans);
        v.pop_back();
        //not take
        recurse(candidates, target, i + 1, v, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        recurse(candidates, target, 0, v, ans);
        return ans;
    }
};
