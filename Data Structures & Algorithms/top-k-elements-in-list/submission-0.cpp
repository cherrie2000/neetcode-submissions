class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
      sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
});

        vector<int> ans;
        for(auto it:v){
          if(k==0)
          break;
          ans.push_back(it.second); k--;
        }
        return ans;
    }
};
