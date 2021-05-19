//Leetcode problem
//Here we will negate the values if we see that any digit which is already negative is dubicate 
//then add it to vector

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i])-1;
            if (nums[index]<0){
                v.push_back(abs(nums[i]));
            }
            nums[index]= -nums[index];
        }
        return v;
    }
};