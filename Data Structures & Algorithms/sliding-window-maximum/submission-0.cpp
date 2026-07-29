class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
               int i=0, j=0;
        deque<int> d;
        vector<int> ans;
        while(j<nums.size()){
            while(!d.empty() && d.back()<nums[j]){
                d.pop_back();
            }
            d.push_back(nums[j]);

            if(j-i+1==k){
                ans.push_back(d.front());
                if(nums[i]==d.front()) d.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};
