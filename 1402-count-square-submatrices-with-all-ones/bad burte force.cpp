#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int n=matrix.size();// y
        int m=matrix[0].size();//x
        int max_size=min(n,m);
        //cout<<n<<m<<max_size<<endl;
        for(int sz=1;sz<=max_size;sz++)
        {
            //cout<<"!sz="<<sz<<endl;
            for(int x=0;x<=m-sz;x++)
            {
                for(int y=0;y<=n-sz;y++)
                {
                    bool flag=true;
                    //cout<<x<<" "<<y<<" "<<sz<<endl;
                    for(int i=0;i<sz;i++)
                    {
                        for(int j=0;j<=i;j++)
                        {
                            for(int k=0;k<=i;k++)
                            {
                                if(matrix[y+j][x+k]==0)
                                {
                                    flag=false;
                                    break;
                                }
                            }
                            if(flag==false)
                            {
                                break;
                            }
                        }
                        if(flag==false)
                            {
                                break;
                            }

                    }
                    if(flag)
                    {
                        ans++;
                    }
                }

            }
        }
        return ans;
    }
};