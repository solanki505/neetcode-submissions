class Solution {
public:
    int rec(int top,int lvl,vector<int>&dp){
        //prusing
        if(lvl>top)return 0;
        //cache check
        if(dp[lvl]!=-1)return dp[lvl];
        //base case
        if(lvl==top)return 1;
        return dp[lvl]=rec(top,lvl+1,dp)+rec(top,lvl+2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return rec(n,0,dp);
    }
};
