class Solution {
public:
    void subset(int ind, int n, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){

        ans.push_back(ds);
        
        for(int i=ind;i<n;i++){
            if(i>ind and nums[i] == nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            subset(i+1,n,nums,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        vector<vector<int>> ans;
        subset(0,nums.size(),nums,ds,ans);
        return ans;
    }
};