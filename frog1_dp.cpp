#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
const int INF = 1e8+10;
int dp[N];
int height[N];

int minCost(int n){
  if(n==0) return 0;
  if(n==1) return abs(height[n]-height[n-1]);
  if(dp[n] != INF) return dp[n];
  return dp[n]=min((minCost(n-1)+abs(height[n-1]-height[n])),(minCost(n-2)+abs(height[n-2]-height[n])));
}

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>height[i];
  for(int i=0;i<n;i++) dp[i]=INF;
  cout<<minCost(n-1)<<endl;
}