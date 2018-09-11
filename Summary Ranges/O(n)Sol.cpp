class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        
        if(nums.size() == 0) {
            return ans;
        }
        if(nums.size() == 1) {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        
        int rangeStart = 0;
        int prevNum = nums[0];
        for(int i = 1; i<=nums.size();i++) {
            if(i == nums.size()) {
                if(rangeStart == i-1){
                    ans.push_back(to_string(nums[rangeStart]));
                } else {
                    ans.push_back(to_string(nums[rangeStart])+"->"+to_string(nums[i-1]));
                }
                break;
            }
            if(nums[i] != prevNum + 1) {
                if(rangeStart == i-1){
                    ans.push_back(to_string(nums[rangeStart]));
                } else {
                    ans.push_back(to_string(nums[rangeStart])+"->"+to_string(nums[i-1]));
                }
                rangeStart = i;
            }
            prevNum = nums[i];
        }
        
        return ans;
    }
};