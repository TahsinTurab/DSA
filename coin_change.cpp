class Solution {
public:
    long long dp[10010];
    int fun(int amount, vector<int>& coins){
        if(amount == 0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        long long ans = INT_MAX;
        for(auto coin : coins){
            if(amount-coin>=0){
                ans = min(ans, fun(amount-coin,coins)+1LL);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0;i<10010;i++) dp[i]=-1;
        long long ans = fun(amount, coins);
        return ans==INT_MAX ? -1 : ans;
    }
};