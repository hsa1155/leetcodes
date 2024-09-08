#include "bits/stdc++.h"
using namespace std;



class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *current1 = list1;
        ListNode *current2 = list2;
        ListNode *newhead;
        ListNode *current_new;

        if(current1==nullptr&&current2==nullptr)
        {
            return nullptr;
        }

        if (current1 == nullptr)
        {
            newhead = current2;
            current2 = current2->next;
        }
        else if (current2 == nullptr)
        {
            newhead = current1;
            current1 = current1->next;
        }
        else if (current1->val >= current2->val)
        {
            newhead = current2;
            current2 = current2->next;
        }
        else
        {
            newhead = current1;
            current1 = current1->next;
        }
        current_new = newhead;

        while (current1 || current2)
        {
            if (current1 == nullptr)
            {
                current_new->next=current2;
                current2=current2->next;

            }
            else if (current2 == nullptr)
            {
                current_new->next=current1;
                current1=current1->next;
            }
            else if (current1->val >= current2->val)
            {
                current_new->next=current2;
                current2=current2->next;
            }
            else
            {
                current_new->next=current1;
                current1=current1->next;
            }
            current_new=current_new->next;
        }

        return newhead;
    }
};