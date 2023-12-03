#include<iostream>
#include<algorithm>
#include<limits.h>
#include<utility>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int vis[N];

//dfs application: 
// connected components
// find cycle in graph
// find diameter
// subtree sum
// even off count in subtree
// lowest common ancestor
// edge delation

bool isCycleExist(int v,int par){
	bool ans = false;
	vis[v]=true;
	for(auto child:g[v]){
		if(vis[child] && child==par) continue;
		if(vis[child]) return true;
		else ans |= isCycleExist(child,v);
	}
	return ans;
}

void dfs(int v){
	if(vis[v]) return;
	vis[v]=true;
	//cout<<v<<" ";
	for(auto child:g[v]){
		dfs(child);
	}
}

int main(){
	int node, edge;
	cin>>node>>edge;
	for(int i=0;i<edge;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	//dfs(1);
	// To find connected components,
	// run dfs for each unvisited node and count;
	// int cc=0;
	// for(int i=1;i<=node;i++){
	// 	if(vis[i]) continue;
	// 	else{
	// 		cc++;
	// 		dfs(i);
	// 	}
	// }

	// cout<<"total connected components: "<<cc<<endl;
	cout<<"Is cycle exist? : "<<isCycleExist(1,0)<<endl;
}