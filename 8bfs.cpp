#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
const int N = 1e5+10;

using namespace std;

bool vis[N];
vector<int>g[N];
int level[N];

void bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source]=true;
	while(!q.empty()){
		int crrV = q.front();
		q.pop();
		for(auto child:g[crrV]){
			if(!vis[child]){
				q.push(child);
				vis[child]=true;
				level[child]=level[crrV]+1;
			}
		}
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
	bfs(1);
	for(int i=1;i<=n;i++) cout<<i<<"-"<<level[i]<<endl;
}