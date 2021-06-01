// BRUTE FORCE NOT GOOD O(N*N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3){
            return 0;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            int leftmx=0, rightmx=0;
            for(int j=i-1;j>=0;j--){
                if(height[i]<height[j]){
                    leftmx=max(leftmx,height[j]-height[i]);
                }
            }
            for(int j=i+1;j<n;j++){
                if(height[i]<height[j]){
                    rightmx=max(rightmx,height[j]-height[i]);
                }
            }
            //cout<<leftmx<<" "<<rightmx<<endl;
            ans+=min(rightmx,leftmx);
        }
        return ans;
    }
};

//Little better approach using two arrays
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3){
            return 0;
        }
        int left[n];
        int leftmax=0;
        for(int i=0;i<n;i++){
            leftmax=max(leftmax,height[i]);
            left[i]=leftmax;
        }
        int right[n];
        int rightmax=0;
        for(int i=n-1;i>=0;i--){
            rightmax=max(rightmax,height[i]);
            right[i]=rightmax;
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=min(left[i],right[i])-height[i];
        }
        return res;
    }
};

//Best approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int leftmx=0,rightmx=0;
        int res=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>leftmx){
                    leftmx=height[l];
                }
                else{
                    res+=leftmx-height[l];
                }
                l++;
            }
            else{
                if(height[r]>rightmx){
                    rightmx=height[r];
                }
                else{
                    res+=rightmx-height[r];
                }
                r--;
            }
        }
        return res;
    }
};