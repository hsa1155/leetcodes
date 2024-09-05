#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *dummy=new ListNode(-1,head);
        ListNode *current=head;
        ListNode *slow=head;
        ListNode *from=dummy;//from of slow
        int currentIndex=0;
        int slowIneex=0;

        while (current)
        {
            
            if(current->next)
            {
                if(currentIndex+1-slowIneex>=n)
                {
                    currentIndex++;
                    slowIneex++;
                    from=slow;
                    slow=slow->next;
                    current=current->next;
                }
                else
                {
                    currentIndex++;
                    current=current->next;
                }
            }
            else
            {
                //at the end
                from->next=slow->next;
                delete slow;
                break;
            }
        }
        
        


        


        ListNode *result=dummy->next;
        delete dummy;
        return result;
        
    }
};