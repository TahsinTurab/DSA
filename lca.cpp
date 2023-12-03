#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int parent[N];
vector<int>g[N];

void dfs(int vertex, int par=-1)
{
	parent[vertex]=par;
	for(auto &child:g[vertex]){
		if(child==par) continue;
		dfs(child,vertex);
	}
}

vector<int> path(int vertex){
	vector<int> ans;
	while(vertex!=-1){
		ans.push_back(vertex);
		vertex=parent[vertex];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1);
	int v1,v2;
	cin>>v1>>v2;
	int lca=-1;
	auto path1 = path(v1);
	auto path2 = path(v2);
	int i=0;
	//cout<<path1.size()<<" "<<path2.size()<<endl;
	while(i<path1.size() && i<path2.size()){
		if(path1[i]!=path2[i]) break;
		else lca=path1[i];
		i++;
	}
	cout<<lca<<endl;
}	