class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = nums[0];
        int startIndex = 0;
        int endIndex = 0;
        for(int i = 0; i<nums.size();i++){
            int sums = nums[i];
            if(sums>largest){
                    largest = sums;
                    startIndex = i;
                    endIndex = i;
                }
            for(int j = i+1; j<nums.size();j++){
                sums+= nums[j];
                if(sums>largest){
                    largest = sums;
                    startIndex = i;
                    endIndex = j;
                }
            }   
        }
        
        return largest;
    }
};