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


void dfs(int v, int par){
	for(auto child:g[v]){
		if(child==par) continue;
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
	dfs(1);
	
}