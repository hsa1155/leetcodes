#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> right;

        for(int x:asteroids)
        {
            if(x<0)
            {
                bool explode=false;
                while (!right.empty())
                {
                    if(right.top()<abs(x))
                    {
                        right.pop();
                    }
                    else if(right.top()==abs(x))
                    {
                        explode=true;
                        right.pop();
                        break;
                    }
                    else
                    {
                        explode=true;
                        break;

                    }
                }
                if(!explode)
                {
                    result.push_back(x);
                }
                
            }
            else
            {
                right.push(x);
            }
        }
        stack<int> left;

        while (!right.empty())
        {
            left.push(right.top());
            right.pop();
        }

        while (!left.empty())
        {
            result.push_back(left.top());
            left.pop();
            /* code */
        }
        
        

        return result;
        
    }
};