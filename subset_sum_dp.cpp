#include<iostream>
#include <limits.h>
#include<vector>
#include <set>
#include<cstring>

using namespace std;

int dp[105][105];

bool isSubsetSumPossible(int *a, int sum_left, int idx){
	if(sum_left==0) return true;
	if(idx<0 || sum_left<0) return false;
	if(dp[idx][sum_left]!=false) return dp[idx][sum_left];
	bool ans = false;
	ans |= isSubsetSumPossible(a,sum_left,idx-1);
	ans |= isSubsetSumPossible(a,sum_left-a[idx],idx-1);
	return dp[idx][sum_left]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp))
	int n,s;
	cin>>n>>s;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	cout<<isSubsetSumPossible(a,s,n-1)<<endl;
}