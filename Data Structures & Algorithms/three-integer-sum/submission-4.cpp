class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int temp = nums[i];
            int j=i+1, k=nums.size()-1;
           // cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<"\n";
            while(j<k){
               int sum= nums[j]+nums[k]+temp;
                if(sum>0){
                    
                    k--;
   
                }
                else if(nums[k]+nums[j]+temp<0){
                    j++;
                }
                else{
                  
                    ans.push_back({temp,nums[j],nums[k]});
                    j++; k--;
                    while(j<k && nums[k]==nums[k+1])
                    k--;
                } 

            }
            //cout<<"\n"<<"\n";
        }
        return ans;
    }
};
