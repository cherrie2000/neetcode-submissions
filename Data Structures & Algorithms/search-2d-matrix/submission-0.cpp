class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
      int col = matrix[0].size();  
      int i=0, j=row*col-1;
      while(i<=j){
        int mid = i+(j-i)/2;
        int mid_i = mid/col;
        int mid_j = mid%col;
        if(matrix[mid_i][mid_j]==target) return true;
        if(matrix[mid_i][mid_j]>target){
            j=mid-1;
        }
        else{
            i=mid+1;
            
        }
      }
      return false;
    }
};
