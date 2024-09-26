#include "bits/stdc++.h"
using namespace std;
class MyCalendar {
    map<int,int> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        if(calendar.empty())
        {
            calendar.insert({start,end});
            return true;
        }
        else
        {
            auto it=calendar.lower_bound(end);
            //find first start time >=end
            if(it==calendar.begin())
            {
                //before first event
                calendar.insert({start,end});
                return true;
            }
            else 
            {
                if(prev(it,1)->second>start)
                {
                    return false;
                }
                else
                {
                    calendar.insert({start,end});
                    return true;
                }

            }
            return false;



        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */