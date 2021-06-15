class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        string st=strs[0];
        for(int i=0;i<n-1;i++){
            int ln = min(st.length(),strs[i+1].size());
            if(ln==0){
                return "";
            }
            string ans;
            for(int j=0;j<ln;j++){
                if(st[j]==strs[i+1][j]){
                    ans+=st[j];
                }
                else{
                    break;
                }
            }
            if(ans.length()==0){
                return "";
            }
            st=ans;
        }
        return st;
    }
};