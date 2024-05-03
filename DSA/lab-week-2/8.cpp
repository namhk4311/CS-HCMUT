#include<cctype>
#include<stack>
#include<sstream>
#include<vector>
vector<string> string2vec(string s) {
    vector<string> vec;
    int i = 0, l = s.length();
    while (i<l) {
        string add = "";
        if (s[i]!=' ') {
            while (i < l && s[i]!=' ') {
                add = add + s[i];
                i = i + 1;
            }
            vec.push_back(add);
        }
        i = i + 1;
    }
    
    return vec;
}

// evaluating
int evaluatePostfix(string expr){
    if (expr=="") return 0;
    stack<int> st;
    vector<string> vec = string2vec(expr);
    
    if (vec.size()==1) return stoi(vec[0]);
    
    int i = 0, l = vec.size();
    while (i<l) {
        if (vec[i][0] >= '0' && vec[i][0] <= '9') st.push(stoi(vec[i]));
        else {
            int pre2 = st.top();
            st.pop();
            int pre1 = st.top();
            st.pop();
            
            if (vec[i]=="+") st.push(pre1 + pre2);
            else if (vec[i]=="-") st.push(pre1 - pre2);
            else if (vec[i]=="*") st.push(pre1 * pre2);
            else if (vec[i]=="/") {
                if (pre2==0) return -1;
                st.push(pre1 / pre2);
            }
        }
        i = i + 1;
    }
    
    return st.top();
}