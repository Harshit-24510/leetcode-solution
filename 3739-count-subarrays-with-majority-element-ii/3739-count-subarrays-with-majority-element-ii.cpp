class Solution {
public:
    vector<int> bit;
    int sz;

    void update(int i) {
        for (; i < sz; i += i & -i)
            bit[i]++;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        sz = 2 * n + 5;
        int offset = n + 2;
        bit.assign(sz, 0);

        update(offset);  // register prefix[0] = 0
        int prefix = 0;
        long long ans = 0;

        for (int x : nums) {
            prefix += (x == target) ? 1 : -1;
            ans += query(prefix + offset - 1);  // count prefix sums < current
            update(prefix + offset);
        }

        return ans;
    }
};