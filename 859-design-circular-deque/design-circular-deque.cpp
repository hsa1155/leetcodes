#include "bits/stdc++.h"
using namespace std;
class MyCircularDeque {
    vector<int> deq;
    int st=0;
    int ed=0;
    int k;
    int current=0;
public:
    MyCircularDeque(int k) {
        this->k=k;
        deq=vector<int>(k,-1);
        st=0;
        ed=0;

        
    }
    
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            deq[0]=value;
            st=0;
            ed=0;
            current=1;
            return true;
        }
        else
        {
            st--;
            if(st<0)
            {
                st+=k;
            }
            deq[st]=value;
            current++;
            return true;
        }
        
    }
    
    bool insertLast(int value) {
         if(isFull())
        {
            return false;
        }
        else if(isEmpty())
        {
            deq[0]=value;
            st=0;
            ed=0;
            current=1;
            return true;
        }
        else
        {
            ed++;
            ed%=k;
            deq[ed]=value;
            current++;
            return true;
        }
         
    }
    
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            deq[st]=-1;
            current--;
            st++;
            st%=k;
            return true;
            
        }
        
    }
    
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            deq[ed]=-1;
            current--;
            ed--;
            if(ed<0)
            {
                ed+=k;
            }
            return true;
            
        }
        
    }
    
    int getFront() {
        return deq[st];
        
    }
    
    int getRear() {
         return deq[ed];
    }
    
    bool isEmpty() {
        return current==0;
    }
    
    bool isFull() {
        return current==k;
    };
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */