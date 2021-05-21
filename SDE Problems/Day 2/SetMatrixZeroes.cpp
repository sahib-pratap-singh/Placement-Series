//brute force is that you can check int which row and col is 0 then set 1 to -1 and again looping to change -1 to 0
//ANother brute force is to take two row and col array the filling them accordingly
//My force: :)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vp;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vp.push_back(make_pair(i,j));
                }
            }
        }
        for(int k=0;k<vp.size();k++){
            for(int j=0;j<m;j++){
                matrix[vp[k].first][j]=0;
            }
            for(int j=0;j<n;j++){
                matrix[j][vp[k].second]=0;
            }
        }
    }
};

//Best approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0=1,row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                col0=0;
            }
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=matrix[i][0]=0;
                }
            }
        }
        for(int i=row-1;i>=0;i--){
            for(int j=col-1;j>=1;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==0){
                matrix[i][0]=0;
            }
        }
    }
};