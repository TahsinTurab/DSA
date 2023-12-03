#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5+10;
vector<int> tree[N];
int height[N], depth[N];

void dfs(int vertex, int par){
	for(auto &child:tree[vertex]){
		if(child==par) continue;
		depth[child]=depth[vertex]+1;
		dfs(child,vertex);
		height[vertex] = max(height[vertex],height[child]+1); 
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int v1,v2;
		cin>>v1>>v2;
		tree[v1].push_back(v2);
		tree[v2].push_back(v1);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<depth[i]<<" "<<height[i]<<endl;
	}

}