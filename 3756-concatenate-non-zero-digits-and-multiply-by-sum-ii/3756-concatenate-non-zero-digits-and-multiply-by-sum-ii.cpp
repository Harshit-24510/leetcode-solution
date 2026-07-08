class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long val;
        long long sum;
        int cnt;
        Node(long long v = 0, long long s = 0, int c = 0)
            : val(v), sum(s), cnt(c) {}
    };

    vector<Node> seg;
    vector<long long> pw;

    Node merge(Node &L, Node &R) {
        Node res;
        res.cnt = L.cnt + R.cnt;
        res.sum = L.sum + R.sum;
        res.val = (L.val * pw[R.cnt] + R.val) % MOD;
        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[idx] = Node(0, 0, 0);
            else
                seg[idx] = Node(d, d, 1);
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid, s);
        build(idx * 2 + 1, mid + 1, r, s);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return Node();

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        pw.resize(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        seg.assign(4 * n + 5, Node());

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};