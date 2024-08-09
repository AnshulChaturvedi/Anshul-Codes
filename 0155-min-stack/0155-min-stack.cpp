class MinStack {
public:
    stack<int> st;
    vector<int> mini;
    MinStack() {
        //
    }
    
    void push(int val) {
        st.push(val);
        if(mini.empty() || mini.back() > val){
            mini.push_back(val);
        }
        else{
            mini.push_back(mini.back());
        }
    }
    
    void pop() {
        st.pop();
        mini.pop_back();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */