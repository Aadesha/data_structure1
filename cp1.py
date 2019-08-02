class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if len(s) == 0:
            return 0
        temp = s[0]
        max_len = 1
        for letter in s[1:]:
            
            if letter in temp:
                i = temp.find(letter)
                temp = temp[i+1:]
            temp += letter
            
            if len(temp) > max_len:
                max_len = len(temp)
        return max_len         
        
