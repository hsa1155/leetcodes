#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size();
        int slots=0;
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(),0);

    
        
        if(n==0)
        {
            return true;
        }



        for(int i=1;i<=len;i++)
        {
            if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                slots++;
            }

        }
        cout<<slots<<endl;
        if(slots>=n)
        {
            return true;

        }
        else
        {
            return false;
        }
        
    }
};