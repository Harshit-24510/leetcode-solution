
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        if(k < 1) return -1;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dist[u][cnt]) continue;

            if(u == n - 1) return d;

            for(auto [v, w] : adj[u]) {
                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if(newCnt > k) continue;

                if(d + w < dist[v][newCnt]) {
                    dist[v][newCnt] = d + w;
                    pq.push({d + w, v, newCnt});
                }
            }
        }

        return -1;
    }
};
