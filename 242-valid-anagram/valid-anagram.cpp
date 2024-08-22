class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        int lens=s.length();
        int lent=t.length();
        if(lens!=lent) return false;
        for(int i=0;i<lens;i++)
        {
            hash[s[i]]++;
        }
        for(int i=0;i<lent;i++)
        {
            hash[t[i]]--;
        }

        for(unordered_map<char,int>::iterator it = hash.begin();it!=hash.end();it++)
        {  
            if(it->second !=0)
            {
                return false;
            }

        }
        return true;



    }
};