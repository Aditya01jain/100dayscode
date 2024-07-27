class Solution {
public:
    bool parseBoolExpr(string expression) {
        if(expression.size()==1){
            if(expression=="f") return false;
            else return true;
        }
        stack<char> st;
        for(int i=0; i<expression.size(); i++){
            if(expression[i]!=')'){
                st.push(expression[i]);
            } else{
                vector<char> vec;
                while(st.top()!='('){
                    if(st.top()==',') {st.pop(); continue;}
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();
                if(st.top()=='|'){
                    st.pop();
                    int cnt= count(vec.begin(), vec.end(),'t');
                    if(cnt>=1) st.push('t');
                    else st.push('f');
                } else if(st.top()=='&'){
                    st.pop();
                    int cnt= count(vec.begin(), vec.end(),'t');
                    if(cnt==vec.size()) st.push('t');
                    else st.push('f');
                } else if(st.top()=='!'){
                    st.pop();
                    if(vec[0]=='f') st.push('t');
                    else st.push('f');
                }
            } 
        }
        if(st.top()=='f') return false;
        else return true;
    }
};