class Solution {
public:

    bool isvalid(int m,vector<int>& piles, int k){
        int t=0;
        for(int p:piles){
            t+= ceil(static_cast<double>(p) / m);

        }
        return t<=k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int ans=r;
        while(l<=r){
            int m=(l+r)/2;
            if(isvalid(m,piles,h)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};
