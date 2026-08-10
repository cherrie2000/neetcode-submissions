class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
              int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st; st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]) st.pop();
            left[i] = st.top();
            st.push(i);
        }
        for(auto it:left) cout<<it<<" ";
        st.empty();
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && heights[st.top()]>=heights[i]) st.pop();
            right[i] = st.top();
            st.push(i);
        }
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int temp = heights[i]*(right[i]-left[i]-1);
            maxi = max(maxi,temp);
        }
        return maxi; 
    }
};
