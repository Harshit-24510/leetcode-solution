class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            v.push_back({sum, nums[i]});
        }

        sort(v.begin(), v.end());

        vector<int> target(n);
        vector<tuple<int,int,int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({v[i].first, v[i].second, i});
        }

        
        vector<tuple<int,int,int>> b;
        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            b.push_back({sum, nums[i], i});
        }

        sort(b.begin(), b.end());

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || get<2>(b[i]) == i)
                continue;

            int j = i, cnt = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = get<2>(b[j]);
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};