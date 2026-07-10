class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        // 1. Sort node indices by value
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<long long> val(n);
        for (int i = 0; i < n; i++) val[i] = nums[order[i]];

        // pos[originalIndex] = position in sorted order
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[order[i]] = i;

        // 2. For each sorted position i, farthest[i] = furthest j reachable in ONE hop
        //    (two pointers since val[] is sorted and non-decreasing)
        vector<int> farthest(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while (r + 1 < n && val[r + 1] - val[i] <= maxDiff) r++;
            farthest[i] = r;
        }

        // 3. Connected components via sweeping max-reach (interval merge logic)
        vector<int> comp(n);
        int curComp = 0, curReach = -1;
        for (int i = 0; i < n; i++) {
            if (i > curReach) curComp++;      // gap => new component
            comp[i] = curComp;
            curReach = max(curReach, farthest[i]);
        }

        // 4. Binary lifting table: up[k][i] = farthest index reachable using <= 2^k hops
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = farthest;
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        // 5. Answer each query using binary lifting
        auto minHops = [&](int l, int rr) -> int {
            if (l == rr) return 0;
            if (l > rr) swap(l, rr);
            if (comp[l] != comp[rr]) return -1;

            int cur = l, ans = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < rr) {
                    cur = up[k][cur];
                    ans += (1 << k);
                }
            }
            // cur is now the furthest position reachable that is still < rr
            // one more hop reaches at least farthest[cur] which covers rr
            // (guaranteed since same component)
            if (farthest[cur] >= rr) return ans + 1;
            return -1; // shouldn't happen if same component
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            ans.push_back(minHops(u, v));
        }
        return ans;
    }
};