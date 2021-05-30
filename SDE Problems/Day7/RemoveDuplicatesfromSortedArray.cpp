//Ghatia code
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int cnt=0;
        int i=0;
        int j=0;
        while(i<n-1){
            if(nums[i]==nums[i+1]){
                i++;
                continue;
            }
            else{
                j++;
                nums[j]=nums[i+1];
                cnt++;
            }
            i++;
        }
        
        return cnt+1;
    }
};

//AHA BHADIA MAJEDAR MASSALE WALA CODE
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                nums[i+1-cnt]=nums[i+1];
            }
        }
        return n-cnt;
    }
};