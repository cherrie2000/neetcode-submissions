class Solution {
public:
    int evalRPN(vector<string>& tokens) {
             stack<int> st;
        for(int i=0;i<tokens.size();i++){
          if((tokens[i][0]=='-' && isdigit(tokens[i][1])) || (isdigit(tokens[i][0]))) {   
            bool neg=false; string s="";
            for(auto it:tokens[i]){
                if(it=='-') neg=true;
                else s = s+it;
            }
            int n = neg?-1*stoi(s):stoi(s);
            st.push(n);}
            else{
                int n1 = st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                int n3;
                if(tokens[i]=="/") {
                     n3 = n2/n1; 
                }
                if(tokens[i]=="+") {
                     n3 = n1+n2; 
                }
                if(tokens[i]=="-") {
                     n3 = n2-n1; 
                }
                if(tokens[i]=="*") {
                     n3 = n1*n2; 
                }     
//                cout<<n1<<" "<<" "<<n2<<" "<<tokens[i]<<" "<<n3<<"\n";
                st.push(n3);             
            }
        }
        return st.top();   
    }
};
