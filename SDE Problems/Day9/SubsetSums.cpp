class Solution
{
public:
    void subset(int ind, int sum, int n, vector<int>& arr, vector<int>& sumarr){
        if(ind==n){
            sumarr.push_back(sum);
            return;
        }
        subset(ind+1,sum+arr[ind],n,arr,sumarr);
        subset(ind+1,sum,n,arr,sumarr);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> sumarr;
        subset(0,0,N,arr,sumarr);
        sort(sumarr.begin(),sumarr.end());
        return sumarr;
    }
};