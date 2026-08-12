class Solution {
public:
bool solve(vector<int>&piles, int h, int k){
    int temp=0;
    for(auto it:piles){
        temp+=(it+k-1)/k;
        if(temp>h) return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
               int maxi = INT_MIN;
        for(auto it:piles) maxi=max(maxi,it);
        int i=1,j=maxi;
        int ans=0;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(solve(piles,h,mid)){
                ans=mid;
                j=mid-1;
            }
            else i = mid+1;
        }
        return ans;
    }
};
