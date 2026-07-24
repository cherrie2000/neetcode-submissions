class Solution {
public:
    int characterReplacement(string s, int k) {
               int i=0, j=0;
        map<char,int> mp;
        int maxFreq=0;
        int ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            maxFreq = max(maxFreq,mp[s[j]]);
            int  window_len = j-i+1;

            if(window_len-maxFreq>k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
