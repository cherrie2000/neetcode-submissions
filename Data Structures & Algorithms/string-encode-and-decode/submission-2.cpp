class Solution {
public:

    string encode(vector<string>& strs) {
       string res="";
       for(auto it:strs){
        res+= to_string(it.length())+"#"+it;
       }
       return res;
    }

    vector<string> decode(string s) {
      vector<string> ans;
     cout<<s<<"\n";
      int i = 0;
      while(i<s.length()){
        string len = find_len(s,i);
        int size = len.size();
        int n = stoi(len);
        string temp= s.substr(i+size+1,n);
        cout<<i<<" "<<temp<<"\n";
        ans.push_back(temp);
         i+=n+size+1;
      }
      return ans;
    }

    string find_len(string s, int id){
        string num="";
        while(s[id]!='#'){
            num+= s[id];
            id++;
        }
        return num;
    }
};
