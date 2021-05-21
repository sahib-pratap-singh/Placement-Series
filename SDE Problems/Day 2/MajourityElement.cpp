//Using Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        int i;
        for(i=0;i<nums.size();i++){
            um[nums[i]]++;
            if(um[nums[i]]>nums.size()/2){
                return nums[i];
            }
        }
        return nums[i];
    }
};

//More better aaproach

/*  --------------------Moore Voting Algorithm--------------------  */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                cnt++;
                major = nums[i];
            }
            else if(major == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return major;
    }
};