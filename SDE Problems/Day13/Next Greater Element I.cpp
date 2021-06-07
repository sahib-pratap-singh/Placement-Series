//Desi approach

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            bool check=false;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==nums1[i]){
                    check=true;
                }
                if(check and nums2[j]>nums1[i]){
                    v.push_back(nums2[j]);
                    check=false;
                    break;
                }
            }
            if(check == true){
                v.push_back(-1);
            }
        }
        return v;
    }
};

//Kadak approach

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> s;
        unordered_map<int,int> mp;
        for(auto x:nums2){
            while(s.size() and s.top()<x){
                mp[s.top()]=x;
                s.pop();
            }
            s.push(x);
        }
        for(auto x:nums1){
            v.push_back(mp.count(x)==1?mp[x]:-1);
        }
        return v;
    }
};