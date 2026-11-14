class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int sum=INT_MAX;
        
        for(int i=0;i<n;i++){
            int res=0;
            for(int j=i;j<n and j-i+1<=r;j++){
                res+=nums[j];
                int len=j-i+1;
                if(res>0 and len>=l){
                sum=min(res,sum);

            }
           
            }
            
        }
        if(sum==INT_MAX){
            return -1;
        }
        else return sum;


        
    }
};