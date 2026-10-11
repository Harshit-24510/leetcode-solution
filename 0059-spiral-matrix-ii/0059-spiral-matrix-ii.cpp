
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));

        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {

            // left to right
            for (int j = left; j <= right; j++) {
                v[top][j] = num++;
            }
            top++;

            // top to bottom
            for (int i = top; i <= bottom; i++) {
                v[i][right] = num++;
            }
            right--;

            // right to left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    v[bottom][j] = num++;
                }
                bottom--;
            }

            // bottom to top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    v[i][left] = num++;
                }
                left++;
            }
        }

        return v;
    }
};
