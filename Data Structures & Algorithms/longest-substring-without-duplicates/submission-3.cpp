class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
     int i=0; int j=0;
     int ans =1;
        map<char,int> mp;
     while(j<s.size()){
        if(mp.find(s[j])!=mp.end() && mp[s[j]]>0){
            ans = max(ans,j-i);
            //cout<<i<<" "<<j<<" "<<ans<<"\n";
            while(i<j){
             //   cout<<i<<" "<<s[i]<<" "<<s[j]<<"   ";
                mp[s[i]]--;
                  if(s[i]==s[j]) break;
                i++;
              
            }
            i++;

        }
        mp[s[j]]++; j++;
     }   
     ans = max(ans,j-i);
        return ans;
    }
};
