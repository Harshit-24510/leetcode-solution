class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int moves=0;
        int min=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            moves+=nums[i]-min;
        }
        return moves;

        
    }
};