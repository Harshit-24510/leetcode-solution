class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string digits = "123456789";

        for (int len = 1; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {
                string sub = digits.substr(i, len);
                int num = stoi(sub);

                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};