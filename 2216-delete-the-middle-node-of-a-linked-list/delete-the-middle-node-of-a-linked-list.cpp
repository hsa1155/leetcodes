#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *dummy=new ListNode(-1,head);
        ListNode *current=head;
        ListNode *prev=dummy;
        int count=0;

        while (current)
        {
            count++;
            current=current->next;
        }

        int to_delete=count/2;
        current=head;
        count=0;

        while (count!=to_delete)
        {
            ListNode *tmp=current;
            current=current->next;
            prev=tmp;
            count++;
        }

        prev->next=current->next;
        
        ListNode *result=dummy->next;
        delete dummy;
        return result;

        
    }
};