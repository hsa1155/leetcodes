#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy=nullptr;
        ListNode *current=head;
        ListNode *Last=dummy;
        vector<int> result;

        while(current!=nullptr)
        {
            ListNode *tmp=current->next;
            current->next=Last;
            Last=current;
            current=tmp;
            
        }

        return Last;

        
    }
};