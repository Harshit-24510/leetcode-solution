class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int cumsum=0;
        mp[0]=1;
        long long left=0;
        long long ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==target){
                left+=mp[cumsum];
                cumsum+=1;
    
            }
            else{
                cumsum-=1;
                left-=mp[cumsum];
            }
            mp[cumsum]+=1;
            ans+=left;

        }
        return ans;

        
    }
};