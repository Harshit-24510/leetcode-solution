#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns true iff we can reach (m‑1,n‑1) while health never drops ≤ 0.
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (health <= 0) return false;                 // cannot start

        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));

        // Cost of the starting cell (0 if safe, 1 if unsafe)
        dist[0][0] = grid[0][0];
        deque<pair<int,int>> dq;
        dq.emplace_back(0, 0);

        const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!dq.empty()) {
            auto [i, j] = dq.front(); dq.pop_front();
            int cur = dist[i][j];

            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;

                int nd = cur + grid[ni][nj];          // new cost if we step onto (ni,nj)
                if (nd < dist[ni][nj]) {
                    dist[ni][nj] = nd;
                    if (grid[ni][nj] == 0) {
                        dq.emplace_front(ni, nj);      // 0‑weight edge → front of deque
                    } else {
                        dq.emplace_back(ni, nj);       // 1‑weight edge → back of deque
                    }
                }
            }
        }

        int minCost = dist[m-1][n-1];
        // Feasible iff total unsafe cells ≤ health‑1 (so health stays ≥ 1)
        return minCost <= health - 1;
    }
};
