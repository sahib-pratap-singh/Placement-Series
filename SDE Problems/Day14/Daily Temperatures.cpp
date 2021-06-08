class Solution {
public:
    vector<int> nsr(vector<int> heights,int n){
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(n);
            }
            else if(s.size() and s.top().first>heights[i]){
                v.push_back(s.top().second);
            }
            else if(s.size() and s.top().first<=heights[i]){
                while(s.size() and s.top().first<=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(n);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push(make_pair(heights[i],i));
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i]==n){
                v[i]=0;
            }
            else{
                v[i]=v[i]-i;
            }
        }
        return v;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return nsr(temperatures,temperatures.size());
    }
};