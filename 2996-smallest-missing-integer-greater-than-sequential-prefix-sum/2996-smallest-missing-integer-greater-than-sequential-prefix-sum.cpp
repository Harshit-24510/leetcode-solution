class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] == nums[i] + 1)
                sum += nums[i + 1];
            else
                break;
        }
        set<int> st(nums.begin(), nums.end());
        while(st.count(sum))
            sum++;
        return sum;
    }
};