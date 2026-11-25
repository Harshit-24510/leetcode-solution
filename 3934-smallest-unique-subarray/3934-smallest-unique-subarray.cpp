class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), temp(n);

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        for(int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        for(int k = 1; k < n; k *= 2) {
            auto cmp = [&](int a, int b) {
                if(rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + k < n) ? rank[a + k] : -1;
                int rb = (b + k < n) ? rank[b + k] : -1;

                return ra < rb;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for(int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }

            rank = temp;

            if(rank[sa[n - 1]] == n - 1)
                break;
        }

        vector<int> pos(n), lcp(n, 0);

        for(int i = 0; i < n; i++)
            pos[sa[i]] = i;

        int h = 0;

        for(int i = 0; i < n; i++) {
            if(pos[i] == 0)
                continue;

            int j = sa[pos[i] - 1];

            while(i + h < n && j + h < n && nums[i + h] == nums[j + h])
                h++;

            lcp[pos[i]] = h;

            if(h > 0)
                h--;
        }

        int ans = n;

        for(int i = 0; i < n; i++) {
            int common = lcp[i];

            if(i + 1 < n)
                common = max(common, lcp[i + 1]);

            int len = common + 1;

            if(sa[i] + len <= n)
                ans = min(ans, len);
        }

        return ans;
    }
};