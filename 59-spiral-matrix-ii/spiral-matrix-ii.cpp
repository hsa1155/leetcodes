class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int n2=n*n;
        int i=0;
        int j=0;

        vector<vector<int>> result(n,vector<int>(n,-1));
        result[0][0]=1;
        for(int k=1;k<=n2;k++)
        {
            

            while(j<n-1)
            {
                if(result[i][j+1]==-1)
                {
                    j++;
                    k++;
                    result[i][j]=k;
                }
                else
                {
                    break;
                }

            }
            while(i<n-1)
            {
                if(result[i+1][j]==-1)
                {
                    i++;
                    k++;
                    result[i][j]=k;
                }
                else
                {
                    break;
                }

            }
            while(j>0)
            {
                if(result[i][j-1]==-1)
                {
                    j--;
                    k++;
                    result[i][j]=k;
                }
                else
                {
                    break;
                }

            }
            while(i>0)
            {
                if(result[i-1][j]==-1)
                {
                    i--;
                    k++;
                    result[i][j]=k;
                }
                else
                {
                    break;
                }

            }
            if(k==n2) break;
            k--;
        }
        return result;
    }
};