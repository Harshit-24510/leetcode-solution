class Solution {
public:
    long long sumAndMultiply(int n) {
        string res;

        for (char c : to_string(n)) {
            if (c != '0')
                res += c;
        }

        if (res.empty())
            return 0;

        long long x = stoll(res);
        long long sum = 0;

        for (char c : res)
            sum += c - '0';

        return sum * x;
    }
};