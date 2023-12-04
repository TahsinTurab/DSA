#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+10;
bool vis[N];
int ssum[N];
vector<int> g[N];

void dfs(int v, int par=0){
	ssum[v]+=v;
	for(auto child:g[v]){
		if(child==par) continue;
		dfs(child,v);
		ssum[v]+=ssum[child];
		
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1);
	for(int i=1;i<=n;i++) cout<<ssum[i]<<endl;
	//cout<<ssum[5]<<endl;
}