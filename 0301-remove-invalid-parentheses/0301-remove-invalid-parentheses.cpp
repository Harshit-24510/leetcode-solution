class Solution {
public:
    vector<string> ans;

    bool isValid(string s) {
        int cnt = 0;

        for(char c : s) {
            if(c == '(') {
                cnt++;
            }
            else if(c == ')') {
                cnt--;

                if(cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }

    void solve(string s, int start, int removeLeft, int removeRight) {
        if(removeLeft == 0 && removeRight == 0) {
            if(isValid(s)) {
                ans.push_back(s);
            }
            return;
        }

        for(int i = start; i < s.size(); i++) {

            // Duplicate removal avoid karo
            if(i > start && s[i] == s[i-1])
                continue;

            // Sirf parentheses remove karne hain
            if(s[i] != '(' && s[i] != ')')
                continue;

            string temp = s.substr(0, i) + s.substr(i + 1);

            if(s[i] == '(' && removeLeft > 0) {
                solve(temp, i, removeLeft - 1, removeRight);
            }

            if(s[i] == ')' && removeRight > 0) {
                solve(temp, i, removeLeft, removeRight - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int removeLeft = 0;
        int removeRight = 0;

        // Minimum number of '(' and ')' jo remove karne hain
        for(char c : s) {

            if(c == '(') {
                removeLeft++;
            }
            else if(c == ')') {

                if(removeLeft > 0)
                    removeLeft--;
                else
                    removeRight++;
            }
        }

        solve(s, 0, removeLeft, removeRight);

        return ans;
    }
};