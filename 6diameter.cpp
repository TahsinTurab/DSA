//first e 1 k root dhore max depth er 
// child ber korbo
// erpor oi child k root dhore depth
// ber korle max depth e hobe ans
#include<iostream>
#include<vector>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int depth[N];
void dfs(int vertex,int par){
	for(auto &child:g[vertex]){
		if(child==par) continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
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

	dfs(1,0);
	int max_depth=-1;
	int max_depth_node;
	for(int i=1;i<=n;i++){
		if(depth[i]>max_depth){
			max_depth=depth[i];
			max_depth_node=i;
		}
		depth[i]=0;
	}

	dfs(max_depth_node,0);
	int ans=-1;
	for(int i=1;i<=n;i++){
		if(depth[i]>ans) ans=depth[i];
	}

	cout<<ans<<endl;

}