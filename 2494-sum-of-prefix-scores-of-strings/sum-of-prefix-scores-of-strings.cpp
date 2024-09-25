#include "bits/stdc++.h"
using namespace std;

struct tree
{
    int count = 0;
    tree* child[26]={};



    void insert(string &s)
    {
        int n = s.length();
        tree* current = this;
        for(int i = 0; i < n; i++)
        {
            if(current->child[s[i] - 'a'] == nullptr)
            {
                current->child[s[i] - 'a'] = new tree();
                current->child[s[i] - 'a']->count++;
                current = current->child[s[i] - 'a'];
            }
            else
            {
                current->child[s[i] - 'a']->count++;
                current = current->child[s[i] - 'a'];
            }
        }
    }

    int getAns(string &s)
    {
        int n = s.length();
        tree* current = this;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(current->child[s[i] - 'a'] == nullptr)
            {
                return sum;
            }
            else
            {
                sum += current->child[s[i] - 'a']->count;
                current = current->child[s[i] - 'a'];
            }
        }
        return sum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        tree* mytree = new tree();
        vector<int> ans;

        for(string &word : words)
        {
            mytree->insert(word);
        }

        for(string &word : words)
        {
            ans.push_back(mytree->getAns(word));
        }

        return ans;
    }
};
