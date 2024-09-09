#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m,vector<int>(n,-1));
        ListNode* current=head;
        int layer=0;
        int currentm=0;
        int currentn=0;

        while (current)
        {
            currentm=layer;
            currentn=layer;
            if(result[currentm][currentn]!=-1)
            {
                break;
            }
            else
            {
                result[currentm][currentn]=current->val;
                current=current->next;

            }
            for(int i=0;i<n-2*layer-1;i++)
            {
                if(current)
                {
                    result[currentm][++currentn]=current->val;
                    current=current->next;
                }
                else
                {
                    break;
                }
            }
            for(int i=0;i<m-2*layer-1;i++)
            {
                if(current)
                {
                    result[++currentm][currentn]=current->val;
                    current=current->next;
                }
                else
                {
                    break;
                }
            }
            for(int i=0;i<n-2*layer-1;i++)
            {
                if(current)
                {
                    result[currentm][--currentn]=current->val;
                    current=current->next;
                }
                else
                {
                    break;
                }
            }
            for(int i=0;i<m-2*layer-2;i++)
            {
                if(current)
                {
                    result[--currentm][currentn]=current->val;
                    current=current->next;
                }
                else
                {
                    break;
                }
            }
            layer++;
            
        }
        

        return result;
        
    }
};