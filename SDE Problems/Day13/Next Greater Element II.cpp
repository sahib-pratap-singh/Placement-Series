//Brute force

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(-1);
            }
            else if(s.size()>0 and s.top()>nums[i]){
                v.push_back(s.top());
            }
            else if(s.size()>0 and s.top()<=nums[i]){
                while(s.size()>0 and s.top()<=nums[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top());
                }
            }
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
        v.erase(v.begin()+n);
        return v;
    }
};