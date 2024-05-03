int baseballScore(string s){
    int i = 0, l = s.length();
    stack<int> st;
    while (i<l) {
        if (isdigit(s[i])) st.push(s[i]-'0');
        else if (s[i]=='C') st.pop();
        else if (s[i]=='D') st.push(st.top()*2);
        else if (s[i]=='+') {
            int pre = st.top();
            st.pop();
            int add = st.top() + pre;
            st.push(pre);
            st.push(add);
        }
        
        i = i + 1;
    }
    
    int sum = 0; 
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    
    return sum;
}