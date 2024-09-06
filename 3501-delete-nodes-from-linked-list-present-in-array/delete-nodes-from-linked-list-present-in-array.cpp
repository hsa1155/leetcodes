#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy=new ListNode(INT_MAX,head);
        ListNode* current=head;
        ListNode* from=dummy;
        unordered_set<int> removes;

        for(int x:nums)
        {
            removes.insert(x);
        }

        while ((current))
        {
            if(removes.count(current->val)!=0)
            {
                from->next=current->next;
                ListNode* tmp=current;
                current=current->next;
                delete tmp;

            }
            else
            {
            from=current;
            current=current->next;
            }

        }
        


        ListNode* result=dummy->next;
        delete dummy;

        return result;

        
    }
};