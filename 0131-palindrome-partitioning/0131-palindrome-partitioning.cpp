class Solution {
public:
    vector<vector<string>> v;
    vector<string> ans;

    void helper(vector<vector<string>>& v, vector<string>& ans, int i, string& s, int n) {
        if(i == n) {
            v.push_back(ans);
            return;
        }

        for(int j = i; j < n; j++) {
            string temp = s.substr(i, j-i+1);

            if(equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin())) {
                ans.push_back(temp);
                helper(v, ans, j+1, s, n);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        helper(v, ans, 0, s, n);
        return v;
    }
};