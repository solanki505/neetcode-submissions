class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size(),col=matrix[0].size();
        int l=0,r=row*col-1;
        while(l<=r){
            int m=(l+r)/2;
            int ro=m/col;
            int co=m%col;
            if(target<matrix[ro][co]){
                r=m-1;
            }
            else if(target>matrix[ro][co])l=m+1;
            else return true;
        }
        return false;
    }
};
