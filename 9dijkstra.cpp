#include<iostream>
#include<vector>
#include<utility>
#include<queue>
const int N = 1e5+10;
const int INF = 1e9+10;
using namespace std;

vector<pair<int,int>>g[N];
int vis[N];
int dist[N];

int dijkstra(int source,int destnation){
	priority_queue<pair<int,int>> pq;
	pq.push({0,source});
	dist[source]=0;
	while(!pq.empty()){
		auto par = pq.top();
		pq.pop();
		if(vis[par.second]) continue;
		else{
			for(auto child:g[par.second]){
				if(dist[child.first]>(dist[par.second]+child.second)){
					dist[child.first]=dist[par.second]+child.second;
					pq.push({dist[child.first],child.first});
				}
			}
		}
		vis[par.second]=true;
	}
	return dist[destnation];
}

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2,w;
		cin>>v1>>v2>>w;
		g[v1].push_back({v2,w});
	}
	for(int i=0;i<=n;i++) dist[i]=INF;
	cout<<dijkstra(1,6)<<endl;
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
}