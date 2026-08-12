class Solution {
public:
    int findMin(vector<int> &nums) {
                int st=0;int en=nums.size()-1;
        int ans=0;
        while(st<=en){
            int mid = st+(en-st)/2;
            cout<<nums[st]<<" "<<nums[en]<<" "<< nums[mid]<<"\n";
            if(mid<en && nums[mid]>nums[mid+1]) return nums[mid+1];
            if(mid>st && nums[mid]<nums[mid-1]) return nums[mid];
            if(nums[mid]>nums[en]) st=mid+1;
            else en=mid-1;
        }
        return nums[0];
    }
};
