class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int mx=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mn){
                mn=prices[i];
            }
            else if(prices[i]-mn > mx){
                mx=prices[i]-mn;
            }
        }
        return mx;
    }
};

//Kadane;s Algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxh = 0, mxf=0;
        for(int i=1;i<prices.size();i++){
            mxh += prices[i]-prices[i-1];
            mxf=max(mxf,mxh);
            if(mxh<0){
                mxh=0;
            }
        }
        return mxf;
    }
};