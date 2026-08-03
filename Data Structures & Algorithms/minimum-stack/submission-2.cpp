class MinStack {
public:
long min; 
stack<long> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(0);
            min=val;
        }
        else{
            st.push(val-min);
            if(val<min) min=val;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long top = st.top();
        st.pop();
        if(top<0) min = min-top;
    }
    
    int top() {
        if(st.top()>0) 
        return (long)st.top()+min;
        return (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
