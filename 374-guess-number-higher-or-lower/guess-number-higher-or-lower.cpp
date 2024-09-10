#include "bits/stdc++.h"
using namespace std;


class Solution {
public:


    int guessNumber(int n) {
        int left=1;
        int right=n;
        while(left<=right)
        {
            int result=guess((left+(right-left)/2));
            if(result==-1)
            {
                right=(left+(right-left)/2)-1;
            }
            else if(result==0)
            {
                return (left+(right-left)/2);
            }
            else
            {
                left=(left+(right-left)/2)+1;
            }
        }
        return 0;
    }
};