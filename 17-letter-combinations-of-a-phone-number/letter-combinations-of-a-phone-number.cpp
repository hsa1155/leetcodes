class Solution {
public:
    vector<string> letterCombinations(string d) {
        vector<string>v;
        vector<string>temp;
       map<char,vector<string>>mp;
        mp['2']={"a","b","c"};
        mp['3']={"d","e","f"};
        mp['4']={"g","h","i"};
        mp['5']={"k","j","l"};
        mp['6']={"m","n","o"};
        mp['7']={"p","q","r","s"};
        mp['8']={"t","u","v"};
        mp['9']={"w","x","y","z"};
        int n=d.size();
        if(n==0){
            return {};
        }
        for(auto j=0;j<mp[d[0]].size();j++){
                v.push_back(mp[d[0]][j]);
            }
        for(int i=1;i<n;i++){
            //對於每個數字，舉這個數字對應的每個字母，分別插入到答案字串中每一項的後面 ex:現在為a,b,c 下一個對應是d,e,f ->ad,bd,cd,bd....
            for(auto j=0;j<mp[d[i]].size();j++){
                for(int k=0;k<v.size();k++){
                    temp.push_back(v[k]+mp[d[i]][j]);
                }
            }
            v=temp;
            temp.clear();
        }
        return v;
    }
};