class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int zero=0;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]==0) zero++;
        }
        if(zero==n) return false;
        else return true;
        
    }
};