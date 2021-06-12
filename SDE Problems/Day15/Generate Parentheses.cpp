class Solution {
public:
    void paranthesis(int open, int close, string s, vector<string> &v){
        if(open==0 and close==0){
            v.push_back(s);
            return;
        }
        if(open!=0){
            string op1=s;
            op1+="(";
            paranthesis(open-1,close,op1,v);
        }
        if(close>open){
            string op2=s;
            op2+=")";
            paranthesis(open,close-1,op2,v);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        string s="";
        vector<string> v;
        paranthesis(open,close,s,v);
        return v;
    }
};