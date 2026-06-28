class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        vector<int>ans;
        for( auto & it:mpp){
            if(it.second==2){
                ans.push_back(it.first);

            }
        }
        int res=0;
        for(int i=0;i<ans.size();i++){
            res^=ans[i];
        }
        return res;
        
    }
};