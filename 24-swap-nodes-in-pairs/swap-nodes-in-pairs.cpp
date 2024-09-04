#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *current=head;
        ListNode *dummy=new ListNode(-1,head);
        ListNode *from=dummy;

        while(current&&current->next)
        {
            from->next=current->next;
            ListNode *tmp=current->next;
            current->next=current->next->next;
            tmp->next=current;
            from=current;
            current=current->next;
            
        }


        ListNode *ans=dummy->next;
        delete(dummy);
        return ans;
        
    }
};