class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build original tree
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        // Find new parents using DFS
        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';
            int prev = last[ch];

            if(node != 0 && prev != -1) {
                newParent[node] = prev;
            }
            else {
                newParent[node] = parent[node];
            }

            last[ch] = node;

            for(int child : adj[node]) {
                dfs(child);
            }

            last[ch] = prev;
        };

        dfs(0);

        // Build modified tree
        vector<vector<int>> tree(n);

        for(int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        vector<int> ans(n, 1);

        function<int(int)> solve = [&](int node) {
            for(int child : tree[node]) {
                ans[node] += solve(child);
            }

            return ans[node];
        };

        solve(0);

        return ans;
    }
};