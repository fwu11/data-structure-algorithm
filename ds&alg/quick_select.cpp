// use quick select
// which involves the idea of partition
// template
// use left <= right so the condition ends
// [...,right ptr, pivot, left ptr,...]
// O(n) time, O(1)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size()){
            return -1;
        }
        return quickSelect(nums,0,nums.size()-1,nums.size()-k);
    }
    int quickSelect(vector<int>& nums, int start, int end, int k){
        int left = start;
        int right = end;
        int pivot = nums[(start+end)/2];
        
        //partition begins
        while(left <= right){
            while(left <= right && nums[left] < pivot){
                left++;
            }
            while(left <= right && nums[right] > pivot){
                right--;
            }
            if(left <= right){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
        }
        // partition ends
        
        //belongs to the left half
        if(k <= right){
            return quickSelect(nums,start,right,k);
        }
        //belongs to the right half
        if(k >= left){
            return quickSelect(nums,left,end,k);
        }
        return nums[k];
    }
};
