class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int size=nums.size();
        int i=0,j=size-1;
        int curr=0;
        while(curr<=j){
            //if 0
            if(nums.at(curr)==0){
                swap(nums[i],nums[curr]);
                i++;
                curr++;
            }
            else if(nums.at(curr)==1){
                curr++;
            }
            else{
                swap(nums[j],nums[curr]);
                j--;                    //do not increment it as after swapping agin check if 1 or 0
            }
            
        }
  
    }
};