class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int lo = 0;
        int hi = nums.size()-1;

        while(true) {
            
            if(lo==0 && nums[lo] != nums[lo+1]) {
                return nums[lo];
            } else if (hi == nums.size()-1 && nums[hi] != nums[hi-1]) {
                return nums[hi];
            } else if(lo==hi-1) {
                if(nums[lo] != nums[lo+1] && nums[lo] != nums[lo-1]) {
                return nums[lo];
                } else if(nums[hi] != nums[hi+1] && nums[hi] != nums[hi-1]) {
                    return nums[hi];
                }
            }
            
            int mid = (lo+hi)/2;
        if(mid%2 == 1) {
            if(nums[mid] == nums[mid-1]) {
                lo = mid;
            } else {
                hi = mid;
            }
        } else {
            if(nums[mid+1] == nums[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
            
        }
    }

};