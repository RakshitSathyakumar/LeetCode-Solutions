class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        string t="";
        for(int i=0;i<n/2;i++){
                t+=s[i];
                if(n%(i+1) == 0){
                int len = n/(i+1);
                // cout<<len<<endl;
                string temp="";
                for(int i=0;i<len;i++) temp+=t;
                // cout<<temp<<endl;
                if(temp == s){
                    return true;
                }
            }
        }
        return false;
    }
};