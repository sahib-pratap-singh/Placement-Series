class Solution {
public:
    void subset(int ind, int sum, int n, vector<int>& arr, vector<vector<int>>& sumarr, vector<int> ds){
        if(ind==n){
            sumarr.push_back(ds);
            return;
        }
        if(ind<n){
            ds.push_back(arr[ind]);
            subset(ind+1,sum+arr[ind],n,arr,sumarr,ds);
            ds.pop_back();
        }
        subset(ind+1,sum,n,arr,sumarr,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sumarr;
        vector<int> ds;
        subset(0,0,nums.size(),nums,sumarr,ds);
        sort(sumarr.begin(),sumarr.end());
        return sumarr;
    }
};