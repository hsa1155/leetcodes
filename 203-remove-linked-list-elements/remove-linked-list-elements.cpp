/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;

        ListNode* current_ptr=head;
        ListNode* from_ptr=nullptr;
        while (current_ptr!=nullptr)
        {
            if(current_ptr->val!=val)
            {
                from_ptr=current_ptr;
                current_ptr=current_ptr->next;
            }
            else if(current_ptr==head)
            {
                ListNode* tmp=head;
                current_ptr=head->next;
                head=head->next;
                //delete tmp;
            }
            else
            {
                if(from_ptr!=nullptr)
                {
                    from_ptr->next=current_ptr->next;

                }
 
                ListNode* tmp = current_ptr;
                current_ptr=current_ptr->next;
                //delete tmp;
            }
        }
        
        return head;
    }
};