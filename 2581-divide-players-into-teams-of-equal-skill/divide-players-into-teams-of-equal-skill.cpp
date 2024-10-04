#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        int sum=0;
        int require=0;
        long long int chemistry=0;
        for(int &x:skill)
        {
            sum+=x;
        }
        if(sum % (n/2)!=0)
        {
            return -1;
        }
        else
        {
            require=sum / (n/2);
        }
        sort(skill.begin(),skill.end());

        for(int i=0;i<n/2;i++)
        {
            if(skill[i]+skill[n-1-i]!=require)
            {
                return -1;
            }
            else
            {
                chemistry+=skill[i]*skill[n-1-i];
            }
        }

        return chemistry;


        
    }
};