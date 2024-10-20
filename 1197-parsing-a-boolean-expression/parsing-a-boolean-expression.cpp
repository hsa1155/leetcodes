#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch:expression)
        {
            if(ch!=')')
            {
                st.push(ch);
            }
            else
            {
                bool hastrue=false;
                bool hasfalse=false;
                while (!st.empty()&&(st.top()!='!'&&st.top()!='&'&&st.top()!='|'))
                {
                    if(st.top()=='t')
                    {
                        hastrue=true;
                    }
                    if(st.top()=='f')
                    {
                        hasfalse=true;
                    }
                    st.pop();
                }

                if(st.empty())
                {
                    cout<<"???"<<endl;
                    continue;
                }

                if(st.top()=='!')
                {
                    if(hastrue&&hasfalse||(!hastrue&&!hasfalse))
                    {
                        cout<<"bugssssssss at !!!"<<endl;
                        return false;
                    }
                    else if(hastrue)
                    {
                        st.pop();
                        st.push('f');
                    }
                    else
                    {
                        st.pop();
                        st.push('t');
                    }
                }
                else if(st.top()=='&')
                {
                    if((!hastrue&&!hasfalse))
                    {
                        cout<<"bugssssssss at &&&"<<endl;
                        return false;
                    }
                    else if(hasfalse)
                    {
                        st.pop();
                        st.push('f');
                    }
                    else
                    {
                        st.pop();
                        st.push('t');
                    }

                }
                else if(st.top()=='|')
                {
                    if((!hastrue&&!hasfalse))
                    {
                        cout<<"bugssssssss at |||"<<endl;
                        return false;
                    }
                    else if(hastrue)
                    {
                        st.pop();
                        st.push('t');
                    }
                    else
                    {
                        st.pop();
                        st.push('f');
                    }

                }
                else
                {
                    cout<<"invalid!!!"<<endl;
                    return false;
                }
                
            }
        }
        if(st.size()!=1)
        {
            cout<<1/0<<endl;
        }
        if(st.top()=='t')
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};