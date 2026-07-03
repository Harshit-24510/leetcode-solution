class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n); // adj[u] = {v, cost}
        vector<int> indeg(n, 0);
        set<int> costsSet;

        for (auto& e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            indeg[v]++;
            costsSet.insert(c);
        }

        // Topological order (Kahn's algorithm) - graph is a DAG
        vector<int> topo;
        vector<int> indegCopy = indeg;
        queue<int> dq;
        for (int i = 0; i < n; i++) {
            if (indegCopy[i] == 0) dq.push(i);
        }
        while (!dq.empty()) {
            int node = dq.front(); dq.pop();
            topo.push_back(node);
            for (auto& [v, c] : adj[node]) {
                if (--indegCopy[v] == 0) dq.push(v);
            }
        }

        vector<int> costs(costsSet.begin(), costsSet.end()); // sorted ascending

        auto feasible = [&](int x) -> bool {
            const long long INF = LLONG_MAX;
            vector<long long> dist(n, INF);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == INF) continue;
                // u must be online to pass through, unless it's the start node
                if (u != 0 && !online[u]) continue;
                for (auto& [v, c] : adj[u]) {
                    if (c < x) continue;
                    // v must be online to pass through, unless it's the destination
                    if (v != n - 1 && !online[v]) continue;
                    if (dist[u] + c < dist[v]) {
                        dist[v] = dist[u] + c;
                    }
                }
            }
            return dist[n - 1] <= k;
        };

        int lo = 0, hi = (int)costs.size() - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (feasible(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};