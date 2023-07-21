class Solution {
public:
    bool compare(string &a,string &b){
        if(a.size() != b.size() + 1) return false;
        int i=0,j=0;
        while(i<a.size()){
            if(a[i] == b[j] && j<b.size()){
                j++;i++;
            }else{
                i++;
            }
        }
        if(j == b.size() && i==a.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string a,string b){
            return a.size() < b.size();
        });
        vector<int> dp(words.size()+1,1);int maxi=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && dp[i] < dp[j] +1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(dp[i],maxi);
        }
        for(auto x:dp) cout<<x<<' ';
        return maxi;
    }
};