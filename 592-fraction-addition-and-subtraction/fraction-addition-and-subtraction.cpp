#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> upper,lower,calculates;
        expression.push_back('\0');
        int len=expression.length();
        int lastNumIndex=0;
        int lastNumLength=0;
        if(expression[0]!='-')
        {
            calculates.push_back('+');
        }
        for(int i=0;i<len;i++)
        {
            if(expression[i]=='/')
            {
                string uppertmp,lowertmp;
                uppertmp=uppertmp.assign(expression,lastNumIndex,lastNumLength);
                upper.push_back(stoi(uppertmp));
                lastNumLength=0;
                int j=i+1;
                while (isdigit(expression[j]))
                {
                    lowertmp.push_back(expression[j]);
                    j++;
                }
                lower.push_back(stoi(lowertmp));
                i+=j-i-1;
                
            }
            else if(expression[i]=='+'||expression[i]=='-')
            {
                calculates.push_back(expression[i]);
                lastNumLength=0;

            }
            else if(isdigit(expression[i]))
            {
                if(lastNumLength==0)
                {
                    lastNumIndex=i;
                    lastNumLength++;
                }
                else
                {
                    lastNumLength++;
                }
            }
        }
        
        int numsCount=upper.size();
        int calsCount=calculates.size();
        int coDenominator=lower[0];
        
        for(int i=1;i<numsCount;i++)
        {
            coDenominator=LMP(coDenominator,lower[i]);

        }
        for(int i=0;i<numsCount;i++)
        {
            
            upper[i]=upper[i]*(coDenominator/lower[i]);

        }
        long long int ans=0;
        int next=0;

        for(int i=0;i<calsCount;i++)
        {
            if(calculates[i]=='+')
            {
                ans+=upper[next];
                next++;
            }
            else
            {
                ans-=upper[next];
                next++;
            }
        }
        cout<<ans/gcd(ans,coDenominator)<<" "<<coDenominator/gcd(ans,coDenominator);
        

        string result;
        string tmp;


        result.append(to_string(ans/gcd(ans,coDenominator)));
        result.push_back('/');
        result.append(to_string(coDenominator/gcd(ans,coDenominator)));

        return result;
        


        
    }

    int gcd(int a,int b)
    {
        if(abs(a)<abs(b))
        {
            swap(a,b);
        }
        if(b==0)
        {
            return abs(a);
        }
        while(a%b!=0)
        {
            int tmp=b;
            b=a%b;
            a=tmp;
        }

        return abs(b);
    }

    int LMP(int a,int b)
    {
        if(a==0||b==0)
        {
            return 0;
        }
        return abs(a/gcd(a,b)*b);
    }
};