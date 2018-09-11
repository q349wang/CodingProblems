class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() >0) {
            int first = -1;
            int index = 0;
            for(int i = 0; i < nums.size();i++) {
                if(nums[i] > 0) {
                    first = nums[i];
                    index = i;
                    break;
                }
            }
            if(first == -1) {
                int sum = nums[0];
                for(int i = 0; i < nums.size();i++) {
                    if(nums[i] > sum) {
                        sum = nums[i];

                    }
                }
                
                return sum;
            }
            
            int ans = first;
            int tempSum = first;
            for(int i = index+1; i < nums.size();i++) {
                if(tempSum + nums[i] >= 0) {
                    tempSum += nums[i];
                } else {
                    
                    if(nums[i] > 0) {
                        tempSum = nums[i];
                    } else {
                    
                    while(i < nums.size() && nums[i] < 0) {
                        i++;
                    }
                    if(i < nums.size()){
                        tempSum = nums[i];
                    }
                    }
                    
                }
                if(tempSum > ans) {
                        ans = tempSum;
                    }
            }
            
            if(tempSum > ans) {
                ans = tempSum;
            }
            
            return ans;
        }
        
    }
};