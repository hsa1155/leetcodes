class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.length();
        if(len==1)
        {
            return false;
        }
        string dupString=s+s;
        if(dupString.substr(1,len*2-2).find(s)!=string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }

        
    }
};