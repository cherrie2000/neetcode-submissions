class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int n=nums.size();
        vector<int> prefix(n+1), suffix(n+1);
        prefix[0]=1, suffix[n]=1;
        for(int i =0;i<n;i++){ 
         
           prefix[i+1] = nums[i]*prefix[i];
       }

       for(int i = n-1;i>=0;i--){
        suffix[i] = suffix[i+1]*nums[i];
       }

       vector<int> ans;
       for(int i = 1;i<=n;i++){

        ans.push_back(prefix[i-1]*suffix[i]);
       }
       return ans;
    }
};
