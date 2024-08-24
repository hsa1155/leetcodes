#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int length=s.length();
        int reversed=0;
        while (1)
        {
            if(length-reversed>=2*k)
            {
                cout<<">=2k"<<endl;
                myReverse(s,reversed,reversed+k-1);

                reversed+=2*k;

            }
            else if(length-reversed<k)
            {
                cout<<"<k"<<endl;
                myReverse(s,reversed,length-1);
                break;

            }
            else
            {
                cout<<"else"<<endl;
                myReverse(s,reversed,reversed+k-1);
                break;

            }
        }
        

        return s;
        
    }

    void myReverse(string &s,int left,int right)
    {
        for(int i=left,j=right;i<=j;i++,j--)
        {
            swap(s[i],s[j]);
        }
        /*
        for(int i=0;i<s.length()-1;i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
        */

    }
};