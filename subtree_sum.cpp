#include<iostream>
#include<vector>
#include<map>
#include<set>
const int N = 1e5+10;
using namespace std;

vector<int> g[N];
// map<int,int> sum;
// map<int,int> odd, even;
int odd[N],even[N],sum[N];

// void dfs(int crrV, int par){
// 	if(g[crrV].size()==0){
// 		sum[crrV]=0;
// 		odd[crrV]=0;
// 		even[crrV]=0;
// 		return;
// 	}
// 	for(auto child:g[crrV]){
// 		if(child==par) continue;
// 		dfs(child,crrV);

// 		sum[crrV] += (sum[child]+child);
// 		if(child%2) odd[crrV] += (odd[child]+1);
// 		else even[crrV] += (even[child]+1);
// 	}
// }

void dfs(int vertex, int par){
	for(auto &child:g[vertex]){
		if(child==par) continue;
		dfs(child,vertex);
		sum[vertex]+=sum[child]+child;
		odd[vertex]+=odd[child];
		even[vertex]+=even[child];
		if(child%2) odd[vertex]++;
		else even[vertex]++;
	}
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1,0);
	int q;
	cin>>q;
	while(q--){
		int v;
		cin>>v;
		cout<<sum[v]<<" "<<even[v]<<" "<<odd[v]<<endl;
	}

	//for(int i=1;i<=n;i++) cout<<sum[i]<<endl;

}