class Solution {
public:
    int countCommas(int n) {
        int comma = 0;

        for (int i = 1000; i <= n; i++) {
            int x = i;  

            while (x >= 1000) {
                x = x / 1000;
                comma++;
            }
        }

        return comma;
    }
};