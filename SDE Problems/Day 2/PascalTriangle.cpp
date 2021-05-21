class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> v;
        vector<vector<int>> ans;
        if(numRows==1){
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        if(numRows>1){
            v.push_back(1);
            ans.push_back(v);
            v.push_back(1);
            ans.push_back(v);
        }
        for(int i=2;i<numRows;i++){
            vector<int> c;
            c.push_back(1);
            for(int j=0;j<i-1;j++){
                c.push_back(v[j]+v[j+1]);
            }
            c.push_back(1);
            ans.push_back(c);
            v=c;
        }
        return ans;
    }
};