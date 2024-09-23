#include "bits/stdc++.h"
using namespace std;


class SmallestInfiniteSet {
private:
int current=0;
priority_queue<int,vector<int>,greater<int>> pq; 
map<int,int> mp;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(pq.empty())
        {
            current++;
            return current;
        }
        else
        {
            if(pq.top()<=current)
            {
                mp[pq.top()]=0;
                int tmp=pq.top();
                pq.pop();
                return tmp;
            }
        }

        return -1;
        
    }
    
    void addBack(int num) {
        if(num>current)
        {
            return;
        }
        else
        {
            if(mp[num]==0)
            {
                mp[num]++;
                pq.push(num);
            }
        }
        
    }
};