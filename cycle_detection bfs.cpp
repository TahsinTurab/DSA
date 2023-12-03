#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
bool vis[N];

bool dfs(int crrV, int par){
	vis[crrV]=true;
	for(auto child:g[crrV]){
		if(vis[child] && child!=par) return true;
		dfs(child,crrV);
	}
	return false;
}

int main(){
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v2].push_back(v1);
		g[v1].push_back(v2);
	}
	bool ans = false;
	for(int i=1;i<=v;i++){
		if(vis[i]) continue;
		else ans|=dfs(i,0);
	}
	cout<<ans<<endl;
}