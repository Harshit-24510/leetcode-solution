
class Solution {
public:
    vector<string> ans;
    map<char, string> mpp;

    void backtrack(int i, string digits, string curr) {
        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mpp[digits[i]];
        for (char c : letters) {
            backtrack(i + 1, digits, curr + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        mpp = {
            {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
        };

        backtrack(0, digits, "");
        return ans;
    }
};
