class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0; int j=heights.size()-1,i=0;

        while(i<j){
            //cout<<i<<" "<<j<<""
            int a = (j-i)*min(heights[i],heights[j]);
            area = max(area,a);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return area;
    }
};
