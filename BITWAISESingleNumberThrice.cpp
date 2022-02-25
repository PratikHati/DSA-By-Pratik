class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int one = 0;
        int two = 0;
        int non_three=0;
        
        for(auto x : nums){
            
            two |= one & x;
            
            one ^= x;
            
            non_three = ~(two & one);
            
            one &= non_three;
            
            two &= non_three;

        }
        
        return one;
    }
};