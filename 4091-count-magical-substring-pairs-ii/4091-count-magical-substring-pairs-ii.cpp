class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        vector<vector<int>> Ls(n);
        vector<int> order;
        int last[26];
        memset(last, -1, sizeof(last));
        for (int j = 0; j < n; j++) {
            int c = s[j] - 'a';
            auto it = find(order.begin(), order.end(), c);
            if (it != order.end()) order.erase(it);
            order.insert(order.begin(), c);
            last[c] = j;
            int m = order.size();
            Ls[j].resize(m);
            for (int t = 0; t < m; t++) {
                int cur = last[order[t]];
                int nxt = (t + 1 < m) ? last[order[t + 1]] : -1;
                Ls[j][t] = cur - nxt;
            }
        }
        order.clear();
        int first[26];
        memset(first, -1, sizeof(first));
        long long ans = 0;
        for (int j = n - 2; j >= 0; j--) {
            int p = j + 1;
            int c = s[p] - 'a';
            auto it = find(order.begin(), order.end(), c);
            if (it != order.end()) order.erase(it);
            order.insert(order.begin(), c);
            first[c] = p;
            int m = min((int)Ls[j].size(), (int)order.size());
            for (int t = 0; t < m; t++) {
                int cur = first[order[t]];
                int nxt = (t + 1 < (int)order.size()) ? first[order[t + 1]] : n;
                ans += (long long)Ls[j][t] * (nxt - cur);
            }
        }
        return ans;
    }
};