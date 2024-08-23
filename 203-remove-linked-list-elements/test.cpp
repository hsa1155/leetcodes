#include"bits/stdc++.h"
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;

        ListNode* current_ptr=head;
        ListNode* from_ptr=head;
        while (current_ptr!=nullptr)
        {
            if(current_ptr->val!=val)
            {
                from_ptr=current_ptr;
                current_ptr=current_ptr->next;
            }
            else
            {
                from_ptr->next=current_ptr->next;
                delete(current_ptr);
                current_ptr=from_ptr->next;
            }
        }
        free(&current_ptr);
        return head;
    }
};