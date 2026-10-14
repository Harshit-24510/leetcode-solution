class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";

        if (sum > 9 * num) return res;

        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            res += char('0' + digit);
            sum -= digit;
        }

        return sum == 0 ? res : "";
    }
};