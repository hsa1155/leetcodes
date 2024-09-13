#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> days;

        int n=temperatures.size();
        vector<int > result(n,0);

        for(int i=0;i<n;i++)
        {

            while (!days.empty() && temperatures[i]>temperatures[days.top()])
            {
                result[days.top()]=i-days.top();
                days.pop();
            }
            days.push(i);

        } 

        return result;
        
    }
};