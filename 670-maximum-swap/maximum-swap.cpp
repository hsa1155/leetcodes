#include "bits/stdc++.h"
using namespace std;

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.length();
        int left = -1;
        int right = n - 1;
        int maxi = 0;
        int index = n - 1;

        // for(int i=n-1;i>=0;i--)
        // {
        //     if(s[i]-'0'>maxi)
        //     {
        //         maxi=s[i]-'0';
        //         index=i;
        //                     while (s[left]-'0'>=maxi&&left<index)
        //     {
        //         cout<<i<<endl;
        //         left++;
        //     }
        //     }

        // }

        while (0 < right)
        {
            if (s[right] - '0' > maxi)
            {
                int tmp0=index;
                index = right;
                maxi = s[right] - '0';
                int tmp=-1;
                for(int i=0;i<index;i++)
                {
                    if(s[i]-'0'<maxi)
                    {
                        tmp=i;
                        break;
                    }
                }
                if(tmp==-1)
                {
                    //if no swap candidate revert index
                    cout<<"revert"<<endl;
                    index=tmp0;

                }
                else
                {
                    left=tmp;
                }
            }

            right--;
        }

        cout << left << endl;
        cout << maxi << " " << index << endl;

        if(left!=-1)
        {
            swap(s[left],s[index]);
        }
        int ans= stoi(s);

        return ans;
    }
};