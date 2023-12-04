#include<iostream>
#include <limits.h>
#include<vector>
#include <set>
#include<cstring>

using namespace std;

int dp[105][105];

int lcs(string &s1, string &s2, int i, int j){
	if(i<0 || j<0) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans = max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
	if(s1[i]==s2[j]) ans = max(ans,lcs(s1,s2,i-1,j-1)+1);
	else ans = max(ans,lcs(s1,s2,i-1,j-1));
	return dp[i][j]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	string s1,s2;
	cin>>s1>>s2;
	cout<<lcs(s1,s2,s1.size()-1,s2.size()-1)<<endl;
}