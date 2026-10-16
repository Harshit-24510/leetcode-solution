class Solution {
public:
    void combination(vector<int>& candidates, int target,vector<vector<int>>& v, vector<int>& s, int i) {

        if (target == 0) {
            v.push_back(s);
            return;
        }

        if (i >= candidates.size() || candidates[i] > target) {
            return;
        }

        // Pick
        s.push_back(candidates[i]);
        combination(candidates, target - candidates[i], v, s, i + 1);
        s.pop_back();

        // Not pick
        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[i]) {
            j++;
        }

        combination(candidates, target, v, s, j);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> s;

        sort(candidates.begin(), candidates.end());

        combination(candidates, target, v, s, 0);

        return v;
    }
};