//Brute Force
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

//Average approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0]>target){
            return false;
        }
        int col=0,row=0;
        int n=matrix.size();
        int m=matrix[0].size();
        if(matrix[n-1][0]<target){
            row=n-1;
        }
        for(int i=0;i<n;i++){
            if(matrix[i][col]>target){
                row=i-1;
                break;
            }
            if(matrix[i][col]==target){
                return true;
            }
        }
        for(int j=0;j<m;j++){
            if(matrix[row][j]==target){
                return true;
            }
        }
        return false;
    }
};

//Best approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0;
        int hi=(n*m)-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(matrix[mid/m][mid%m]==target){
                return 1;
            }
            else if(matrix[mid/m][mid%m] <target){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return false;
    }
};