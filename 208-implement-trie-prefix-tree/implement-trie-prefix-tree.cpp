#include "bits/stdc++.h"
using namespace std;

class Trie {
private:
vector<Trie*> children;
char val='-';
bool isend=false;
public:
    Trie() {
        children=vector<Trie*>(26,nullptr);
    }
    
    void insert(string word) {
        //cout<<word<<endl<<endl;;
        int len=word.length();
        Trie* current=this;
        if(len==0)
        {
            return;
        }
        for(int i=0;i<len;i++)
        {
            if(current->children[word[i]-'a']==nullptr)
            {
                Trie* child=new Trie();
                current->children[word[i]-'a']=child;
                current=child;
                child->val=word[i];
            }
            else
            {
                current=current->children[word[i]-'a'];
            }

        }
        current->isend=true;
        
        
    }
    
    bool search(string word) {
        Trie* current=this;
        int len=word.length();
        bool flag=true;

        for(int i=0;i<len;i++)
        {
            if(current->children[word[i]-'a']==nullptr)
            {
                flag=false;
                break;
            }
            else
            {
                current=current->children[word[i]-'a'];
            }
        }
        if(!current->isend)
        {
            flag=false;
        }



        return flag;
        
    }
    
    bool startsWith(string prefix) {
        Trie* current=this;
        int len=prefix.length();
        bool flag=true;

        for(int i=0;i<len;i++)
        {
            if(current->children[prefix[i]-'a']==nullptr)
            {
                flag=false;
                break;
            }
            else
            {
                current=current->children[prefix[i]-'a'];
            }
        }




        return flag;

        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */