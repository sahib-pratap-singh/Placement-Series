class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int,int>> s;
    int next(int price) {
        int res=1;
        while(!s.empty() and s.top().first<=price){
            res+=s.top().second;
            s.pop();
        }
        s.push({price,res});
        return res;
    }
};