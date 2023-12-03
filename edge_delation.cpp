#include<iostream>
#include<vector>
const int N = 1e5+10;
using namespace std;
vector<int>g[N];
int sub_tree_sum[N];
int weight[N];

void dfs(int vertex, int par=-1){
	sub_tree_sum[vertex]+=vertex;
	for(auto &child:g[vertex]){
		if(child==par) continue;
		dfs(child,vertex);
		sub_tree_sum[vertex]+=sub_tree_sum[child];
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
	// for(int i=1;i<n;i++){
	// 	int w;
	// 	cin>>w;
	// 	weight[i]=w;
	// }
	dfs(1);
	int ans=0;
	for(int i=2;i<n;i++){
		int part1=sub_tree_sum[i];
		int part2=sub_tree_sum[1]-part1;
		ans = max(ans, part1*part2);
	}
	//for(int i=1;i<n;i++) cout<<sub_tree_sum[i]<<endl;
	cout<<ans<<endl;
}