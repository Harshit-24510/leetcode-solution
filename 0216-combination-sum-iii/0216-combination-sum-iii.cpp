class Solution {
public:
    void helper(vector<vector<int>>& v, vector<int>& ans, int k, int n, int i) {
        if(k == 0 && n == 0) {
            v.push_back(ans);
            return;
        }

        if(k == 0 || n <= 0 || i > 9) return;

        ans.push_back(i);
        helper(v, ans, k-1, n-i, i+1);

        ans.pop_back();
        helper(v, ans, k, n, i+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> v;
        vector<int> ans;

        helper(v, ans, k, n, 1);

        return v;
    }
};