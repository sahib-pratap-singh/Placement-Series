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

//Little better approach