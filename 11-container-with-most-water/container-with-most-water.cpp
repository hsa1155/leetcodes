#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int left=0;
        int right=n-1;
        int water=0;
        while (left!=n-1&&right!=0)
        {
            water=max(water,min(h[left],h[right])*abs(right-left));

            if(left==n-1||h[right]<=h[left])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return water;
        
    }
};