class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        used = dict()
        
        maxSub = 0
        currSubIndex = 0
        for i in range(0, len(s)):
            if s[i] in used and used[s[i]] >= currSubIndex:
                if maxSub < i - currSubIndex:
                    maxSub = i - currSubIndex
                currSubIndex = used[s[i]] + 1
                used[s[i]] = i
                
            else:
                used[s[i]] = i
        
        if maxSub < len(s) - currSubIndex:
            maxSub = len(s) - currSubIndex
        return maxSub