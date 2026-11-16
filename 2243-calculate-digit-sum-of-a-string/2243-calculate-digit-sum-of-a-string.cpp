class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k) {
            string res = "";
            string ans = "";
            int count = 0;

            for(int i = 0; i < s.size(); i++) {
                ans += s[i];
                count++;

                if(count == k) {
                    int sum = 0;

                    for(char c : ans) {
                        sum += c - '0';
                    }

                    res += to_string(sum);
                    ans = "";
                    count = 0;
                }
            }

            if(ans != "") {
                int sum = 0;

                for(char c : ans) {
                    sum += c - '0';
                }

                res += to_string(sum);
            }

            s = res;
        }

        return s;
    }
};