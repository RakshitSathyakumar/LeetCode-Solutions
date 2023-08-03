class Solution {
public:
    void f(int ind ,string digits,map<int,string> &mp,string s,vector<string> &res)
    {   
        if(ind == digits.size())
        {
            res.push_back(s);
            return;
        }

            int digi=digits[ind]-'0';
            int sz=mp[digi].size();
            for(int j=0;j<sz;j++)
            {
                s.push_back(mp[digi][j]);
                f(ind+1,digits,mp,s,res);
                s.pop_back();
            }

    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        map<int,string> mp;
        mp[1]="";
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string s;
        vector<string> res;
        f(0,digits,mp,s,res);
        return res;
    }
};