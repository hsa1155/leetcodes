#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int current=1;
        vector<int> result(n,0);

        for(int i=0;i<n;i++)
        {
            result[i]=current;

            if(current*10<=n)
            {
                current*=10;
            }
            else
            {
                if(((current+1)%10!=0)&&current+1<=n)
                {
                    current++;
                }
                else
                {
                    while((current+1)%10==0||current+1>n)
                    {
                        current/=10;
                    }
                    current++;
                }
            }
            
        }


        return result;
        
    }
};