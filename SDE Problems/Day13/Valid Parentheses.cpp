class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s){
            if(x=='(' or x=='[' or x=='{'){
                st.push(x);
            }
            else if(x==')' or x==']' or x=='}'){
                if(st.empty()){
                    return false;
                }
                if(st.top()=='(' and x!=')'){
                    return false;
                }
                if(st.top()=='[' and x!=']'){
                    return false;
                }
                if(st.top()=='{' and x!='}'){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};