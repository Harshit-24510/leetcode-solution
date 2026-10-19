class Solution {
public:
    using ll=long long;
    int MOD=1e9+7;
    vector<vector<int>>p;
    int solve(vector<int>nums){
        int n=nums.size();
        if(n<3)return 1;
        vector<int>left;
        vector<int>right;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        ll x=solve(left)%MOD;
        ll y=solve(right)%MOD;
        //z=n-1Cr
        ll z=p[n-1][left.size()];

        return ((x*y)%MOD*z)%MOD;

    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        p.resize(n+1);
        //pascal
        for(int i=0;i<n;i++){
            p[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                p[i][j]=(p[i-1][j-1]+p[i-1][j])%MOD;
            }
        }
        return (solve(nums)-1)%MOD;

        
        
    }
};