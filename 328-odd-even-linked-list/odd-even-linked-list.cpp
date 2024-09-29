#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode* currentOdd=head;
        ListNode* even=head->next;
        ListNode* currentEven=even;
        ListNode* current=head->next->next;

        while (current)
        {
            if(current->next)
            {
                currentOdd->next=current;
                currentEven->next=current->next;
                currentOdd= currentOdd->next;
                currentEven=currentEven->next;
                current=current->next->next;


            }
            else
            {
                currentOdd->next=current;
                currentOdd=currentOdd->next;
                currentEven->next=nullptr;
                current=current->next;
            }
        }
        currentOdd->next=even;

        return head;  
    }
};