class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int instable_score=*max_element(nums.begin(),nums.begin()+i)-*min_element(nums.begin()+i,nums.end());
            ans.push_back(instable_score);
        }
        int mini=INT_MAX;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<=k){
                mini=min(i,mini);
            }
        }
       if(mini!=INT_MAX) return mini;
       else return -1;

        
    }
};