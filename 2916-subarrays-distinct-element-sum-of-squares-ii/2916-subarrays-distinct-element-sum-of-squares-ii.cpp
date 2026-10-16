class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> st;
    int n;

    void apply(int p, int l, int r, long long v) {
        long long len = r - l + 1;

        st[p].sq = (st[p].sq
            + 2LL * v * st[p].sum
            + len * v % MOD * v) % MOD;

        st[p].sum = (st[p].sum + len * v) % MOD;
        st[p].lazy = (st[p].lazy + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (st[p].lazy == 0 || l == r) return;

        int mid = (l + r) / 2;
        long long v = st[p].lazy;

        apply(p * 2, l, mid, v);
        apply(p * 2 + 1, mid + 1, r, v);

        st[p].lazy = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int mid = (l + r) / 2;

        update(p * 2, l, mid, ql, qr);
        update(p * 2 + 1, mid + 1, r, ql, qr);

        st[p].sum = (st[p * 2].sum
                   + st[p * 2 + 1].sum) % MOD;

        st[p].sq = (st[p * 2].sq
                  + st[p * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        st.assign(4 * n + 5, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last[nums[i]];

            // Add one distinct element to affected subarrays.
            update(1, 0, n - 1, prev + 1, i);

            // Sum of squares for all subarrays ending at i.
            ans = (ans + st[1].sq) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};