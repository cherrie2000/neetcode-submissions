class Solution {
public:
    string minWindow(string s, string t) {
                map<char,int> mp;
        for(auto it:t){
            mp[it]++;
        }

        int i=0,j=0, count=mp.size(), mini=INT_MAX, st=-1;

        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;

            if(count==0){
                while(count==0){
                    if(j-i+1<mini){
                        mini = j-i+1;
                        st=i;
                    }
                    
                    mp[s[i]]++;
                    if(mp[s[i]]>0) count++;

                    i++;
                }
            }
            j++;
        }

        if(mini==INT_MAX) return "";
        return s.substr(st,mini);
    }
};
