class Solution {
public:
    vector<int> nsl(vector<int> heights,int n){
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s.empty()){
                v.push_back(-1);
            }
            else if(s.size() and s.top().first<heights[i]){
                v.push_back(s.top().second);
            }
            else if(s.size() and s.top().first>=heights[i]){
                while(s.size() and s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(s.top().second);
                }
            }
            s.push(make_pair(heights[i],i));
        }
        return v;
    }
    vector<int> nsr(vector<int> heights,int n){
        stack<pair<int,int>> s;
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(n);
            }
            else if(s.size() and s.top().first<heights[i]){
                v.push_back(s.top().second);
            }
            else if(s.size() and s.top().first>=heights[i]){
                while(s.size() and s.top().first>=heights[i]){
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
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left = nsl(heights,n);
        vector<int> right = nsr(heights,n);
        vector<int> width;
        for(int i=0;i<n;i++){
            width.push_back(right[i]-left[i]-1);
        }
        int mx_area=INT_MIN;
        for(int i=0;i<n;i++){
            int area = width[i]*heights[i];
            mx_area = max(mx_area,area);
        }
        return mx_area;
    }
};