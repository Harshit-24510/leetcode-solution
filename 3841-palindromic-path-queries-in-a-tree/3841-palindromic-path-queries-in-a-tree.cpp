class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                               string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<int> tin(n), tout(n), depth(n), parent(n);
        vector<vector<int>> up(LOG, vector<int>(n));
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            parent[u] = p;
            tin[u] = timer++;

            up[0][u] = p;
            for (int j = 1; j < LOG; j++)
                up[j][u] = up[j-1][up[j-1][u]];

            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }

            tout[u] = timer;
        };

        dfs(0, 0);

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }
            return up[0][u];
        };

        vector<int> bit(n);
        for (int i = 0; i < n; i++)
            bit[i] = 1 << (s[i] - 'a');

        vector<int> fenwick(n + 1);

        auto update = [&](int i, int x) {
            for (i++; i <= n; i += i & -i)
                fenwick[i] ^= x;
        };

        auto get = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & -i)
                res ^= fenwick[i];
            return res;
        };

        auto rangeUpdate = [&](int l, int r, int x) {
            update(l, x);
            if (r < n) update(r, x);
        };

        for (int u = 0; u < n; u++) {
            update(tin[u], bit[u]);
            if (tout[u] < n)
                update(tout[u], bit[u]);
        }

        vector<bool> ans;

        for (string q : queries) {
            string op, b;
            int u, v;
            stringstream ss(q);
            ss >> op >> u >> b;

            if (op == "update") {
                int newBit = 1 << (b[0] - 'a');
                int diff = bit[u] ^ newBit;

                if (diff) {
                    rangeUpdate(tin[u], tout[u], diff);
                    bit[u] = newBit;
                }
            } else {
                v = stoi(b);
                int w = lca(u, v);

                int mask = get(tin[u]) ^ get(tin[v]) ^ bit[w];
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};