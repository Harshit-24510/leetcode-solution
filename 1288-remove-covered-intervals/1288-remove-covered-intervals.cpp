class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;

        for (int i = 0; i < intervals.size(); i++) {
            bool covered = false;

            for (int j = 0; j < intervals.size(); j++) {
                if (i == j) continue;

                if (intervals[j][0] <= intervals[i][0] &&
                    intervals[j][1] >= intervals[i][1]) {
                    covered = true;
                    break;
                }
            }

            if (!covered) count++;
        }

        return count;
    }
};