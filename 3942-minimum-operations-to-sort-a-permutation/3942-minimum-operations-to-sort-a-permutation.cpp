class Solution {
public:
    int minOperations(vector<int>& nums) {
        int asc_count=0;
        int n=nums.size();
        int desc_count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==(nums[i-1]+1)%n){
                asc_count++;
            }
            if(nums[i-1]==(nums[i]+1)%n) desc_count++;
        }
        if(asc_count==n-1 and nums[0]==0) return 0;
        if(asc_count==n-1){
            int leftrot=n-nums[0];
            int rightrot=2+nums.back()+1;
            return min(leftrot,rightrot);
        }
        if(desc_count==n-1){
            int left=n-nums.back()+1;
            int right=(nums[0]+1)%n+1;
            return min(left,right);
        }
        
        return -1;
    }
};