#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        int index=0;
        
        while (a>0||b>0||c>0)
        {
            if(a>=b&&a>=c&&a>0)
            {
                if(index>=2)
                {
                    if(ans[index-1]=='a'&&ans[index-2]=='a')
                    {
                        if(b>=c&&b>0)
                        {
                            ans=ans+'b';
                            b--;
                            index++;
                        }
                        else if(c>=b&&c>0)
                        {
                            ans=ans+'c';
                            c--;
                            index++;
                        }
                        else if(b==0&&c==0)
                        {
                            break;
                        }
                    }
                    else
                    {
                        ans=ans+'a';
                        a--;
                        index++;
                    }

                }
                else
                {
                    ans=ans+'a';
                    a--;
                    index++;
                }

            }
            else if(b>=a&&b>=c&&b>0)
            {
                if(index>=2)
                {
                    if(ans[index-1]=='b'&&ans[index-2]=='b')
                    {
                        if(a>=c&&a>0)
                        {
                            ans=ans+'a';
                            a--;
                            index++;
                        }
                        else if(c>=a&&c>0)
                        {
                            ans=ans+'c';
                            c--;
                            index++;
                        }
                        else if(a==0&&c==0)
                        {
                            break;
                        }
                    }
                    else
                    {
                        ans=ans+'b';
                        b--;
                        index++;
                    }

                }
                else
                {
                    ans=ans+'b';
                    b--;
                    index++;
                }
            }
            else if(c>=a&&c>=b&&c>0)
            {
                if(index>=2)
                {
                    if(ans[index-1]=='c'&&ans[index-2]=='c')
                    {
                        if(a>=b&&a>0)
                        {
                            ans=ans+'a';
                            a--;
                            index++;
                        }
                        else if(b>=a&&b>0)
                        {
                            ans=ans+'b';
                            b--;
                            index++;
                        }
                        else if(a==0&&b==0)
                        {
                            break;
                        }
                    }
                    else
                    {
                        ans=ans+'c';
                        c--;
                        index++;
                    }

                }
                else
                {
                    ans=ans+'c';
                    c--;
                    index++;
                }
            }
        }

        return ans;
        
        
        
    }
};