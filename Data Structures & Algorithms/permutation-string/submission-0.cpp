class Solution {
public:
    bool checkInclusion(string s1, string s2) {
               map<char,int> mp1;
        for(auto it:s1){
            mp1[it]++;
        }
        map<char,int> mp2;
        int k = s1.size();
        int i=0, j=0;
        while(j<s2.size()){
            mp2[s2[j]]++;
            if(j-i+1==k){
                bool ans=true;
                for(auto it:mp2){
                    char ch = it.first;
                    int freq = it.second;
                    if(mp1.find(ch)==mp1.end() || ( mp1.find(ch)!=mp1.end() && mp1[ch]!=freq)){ans = false; break;}
                }
                if(ans) return ans;

                mp2[s2[i]]--;
                if(mp2[s2[i]]==0){
                    mp2.erase(s2[i]);
                }
                i++;
            }
            j++;
        }
        return false;
    }
};
