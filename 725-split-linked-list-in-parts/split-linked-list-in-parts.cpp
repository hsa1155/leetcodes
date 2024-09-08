#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k);
        ListNode* current=head;
        int n=0;
        while (current)
        {
            n++;
            current=current->next;
        }
        current=head;
        int avg=n/k;
        int remain=n%k;

        for(int i=0;i<k;i++)
        {
            int plus=0;
            if(remain>0)
            {
                plus=1;
                remain--;
            }
            result[i]=current;
            for(int j=0;j<avg+plus-1;j++)
            {
                if(current)
                {
                    current=current->next;
                }
            }
            if(current)
            {
                ListNode* tmp=current;
                current=current->next;
                tmp->next=nullptr;
            }
        }
        
        return result;
    }
};