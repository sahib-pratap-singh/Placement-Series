class Solution {
public:
    void combi(int ind,int n,vector<int>& candidates, int t, vector<vector<int>>& ans,vector<int>& ds){
        if(ind == n){
            if(t==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[ind]<=t){
            ds.push_back(candidates[ind]);
            combi(ind,n,candidates,t-candidates[ind],ans,ds);
            ds.pop_back();
        }
        combi(ind+1,n,candidates,t,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combi(0,candidates.size(),candidates,target,ans,ds);
        return ans;
    }
};