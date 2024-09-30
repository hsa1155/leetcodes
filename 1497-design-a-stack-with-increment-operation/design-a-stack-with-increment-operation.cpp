#include "bits/stdc++.h"
using namespace std;

class CustomStack {
    vector<int> st;
    int maxSize;
    int current=0;

public:
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        st=vector<int>(maxSize,-1);
        current=0;
        
    }
    
    void push(int x) {
        if(current==maxSize)
        {
            return;
        }
        else
        {
            st[current++]=x;
        }
        
    }
    
    int pop() {
        if(current==0)
        {
            return -1;
        }
        else
        {
            return st[--current];
        }
        
    }
    
    void increment(int k, int val) {
        int index=min(k,current);

        for(int i=0;i<index;i++)
        {
            st[i]+=val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */