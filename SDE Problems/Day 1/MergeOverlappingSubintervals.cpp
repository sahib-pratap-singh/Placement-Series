class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> v = intervals[0];
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(v[1]>=intervals[i][0]){
                v[1]=max(intervals[i][1],v[1]);
            }
            else{
                ans.push_back(v);
                v=intervals[i];
            }
        }
        ans.push_back(v);
        return ans;
    }
};