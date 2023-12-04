#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cstring>
#include<climits>
using namespace std;

int val[105], w[105];

long long dp[105][100005];

long long knapsack(int idx, int wt_left){
	if(idx<0 || wt_left==0) return 0;
	if(dp[idx][wt_left]!=-1) return dp[idx][wt_left];
	//when dont choose
	long long ans = knapsack(idx-1,wt_left);
	//when choose
	if(wt_left-w[idx]>=0)
	ans = max(ans,knapsack(idx-1,wt_left-w[idx])+val[idx]);
	return dp[idx][wt_left]=ans;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int item, kwt;
	cin>>item>>kwt;
	for(int i=0;i<item;i++){
		cin>>w[i]>>val[i];
	}

	cout<<knapsack(item-1,kwt)<<endl;
}