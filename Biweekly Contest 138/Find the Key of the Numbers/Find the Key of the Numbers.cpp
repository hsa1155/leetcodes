#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int d1,d2,d3,d4;

 

        d1=min(num1/1000,num2/1000);
        d1=min(d1,num3/1000);
        cout<<d1<<endl;
        num1-=(num1/1000)*1000;
        num2-=(num2/1000)*1000;
        num3-=(num3/1000)*1000;

        d2=min(num1/100,num2/100);
        d2=min(d2,num3/100);
        num1-=(num1/100)*100;
        num2-=(num2/100)*100;
        num3-=(num3/100)*100;

        d3=min(num1/10,num2/10);
        d3=min(d3,num3/10);
        num1-=(num1/10)*10;
        num2-=(num2/10)*10;
        num3-=(num3/10)*10;

        d4=min(num1,num2);
        d4=min(d4,num3);

        int ans=d1*1000+d2*100+d3*10+d4;
        cout<<d1<<d2<<d3<<d4<<endl;


        return ans;
    }
};