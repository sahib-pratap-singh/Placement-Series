//with O(n) space


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> min_st;
    
    void push(int val) {
        if(min_st.empty() || val<=min_st.top()){
            min_st.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(min_st.top()==st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

//With O(1) space


class MinStack {
public:
    /** initialize your data structure here. */
    long long int min;
    stack<long long int> s; 
    MinStack() {
        
    }
    
    void push(long long int val) {
        if(s.empty()){
            min=val;
            s.push(val);
        }
        else if(val>=min){
            s.push(val);
        }
        else{
            s.push(2*val-min);
            min=val;
        }
    }
    
    void pop() {
        if(s.empty()){
            return;
        }
        else if(s.top()>=min){
            s.pop();
        }
        else{
            min=2*min-s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top()>=min){
            return(s.top());
        }
        return min;
    }
    
    int getMin() {
        return min;
    }
};
