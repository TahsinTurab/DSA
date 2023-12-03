#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
const int N = 1e5+10;
const int INF = INT_MAX;

int h[N];
int cost[N];

int minCost(int n, int k){
	if(n==0) return 0;
	if(cost[n]!=-1) return cost[n];
	
	int Cost = INT_MAX;
	for(int i=1;i<=k;i++){
		if(n-i>=0){
			Cost = min(Cost,minCost(n-i,k)+abs(h[n]-h[n-i]));
		}
	}
	return cost[n]=Cost;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>h[i];
	for(int i=0;i<n;i++) cost[i]=-1;

	cout<<minCost(n-1,k);
}