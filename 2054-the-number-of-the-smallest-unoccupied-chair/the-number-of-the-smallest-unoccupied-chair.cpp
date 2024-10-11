#include "bits/stdc++.h"
using namespace std;
struct CompareVector {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b)
    {
        return a[1] > b[1];  // 使用 > 符號來構建最小堆
    }

};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<int,vector<int>, greater<int>> unoccupied;
        priority_queue<vector<int>,vector<vector<int>>,CompareVector> occupied;//0=come 1=leave 2=index 3=seat 
        int count=0;
        for(int i=0;i<n;i++)
        {
            times[i].push_back(i);
        }
        sort(times.begin(),times.end());

        for(int i=0;i<n;i++)
        {
            int nextSeat;

            while (!occupied.empty()&&occupied.top()[1]<=times[i][0])
            {
                unoccupied.push(occupied.top()[3]);
                occupied.pop();
            }
            

            if(unoccupied.empty())
            {
                nextSeat=count++;
            }
            else
            {
                nextSeat=unoccupied.top();
                unoccupied.pop();
            }

            if(times[i][2]==targetFriend)
            {
                return nextSeat;
            }
            else
            {
                times[i].push_back(nextSeat);
                occupied.push(times[i]);
            }

        }

        return -1;
        
    }


};