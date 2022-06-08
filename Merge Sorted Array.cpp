class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int x = nums1.size()-1;
        int i = m-1;
        int j = n-1;
        
        while(i>=0 && j>=0){
            if(nums1[i] < nums2[j]){
                swap(nums1[x],nums2[j]);
                j--;
                x--;
            }
            else{
                swap(nums1[x],nums1[i]);
                i--;
                x--;
            }
        }
        
        while(i>=0){
            swap(nums1[x],nums1[i]);
            i--;
            x--;
        }
        while(j>=0){
            swap(nums1[x],nums2[j]);
            j--;
            x--;
        }
        return ;
    }
};