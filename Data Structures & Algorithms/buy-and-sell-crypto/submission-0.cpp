class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,l=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>l){ans=max(ans,(prices[i]-l));}
            l=min(l,prices[i]);
        }
        return ans;
    }
};
