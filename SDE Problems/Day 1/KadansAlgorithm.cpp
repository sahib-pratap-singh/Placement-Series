class Solution{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        int maxh=0,mxf=arr[0];
        for(int i=0;i<n;i++){
            maxh+=arr[i];
            mxf = max(mxf,maxh);
            if(maxh<0){
                maxh=0;
            }
        }
        return mxf;
    }
};