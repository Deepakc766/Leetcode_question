class Solution:
    def reverseWords(self, s: str) -> str:
        strs = s.split()     
        strs.reverse()         
        output=""
        for i in range(0,len(strs)):
            output=output + strs[i]
            if(i!=len(strs)-1):
                output+=" "
        return output


        