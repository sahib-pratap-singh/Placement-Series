class Solution {
public:
    void combi(int ind,int n,int t, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans){
        if(t==0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind and candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>t){
                break;
            }
            ds.push_back(candidates[i]);
            combi(i+1,n,t-candidates[i],candidates,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        combi(0,candidates.size(),target,candidates,ds,ans);
        return ans;
    }
};