#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<climits>
#include<limits.h>
#include<algorithm>
#include<utility>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
int level[N];
bool vis[N];

void bfs(int vertex){
	queue<int> q;
	q.push(vertex);
	level[vertex]=1;
	while(!q.empty()){
		int crrV = q.front();
		q.pop();
		for(auto child:g[crrV]){
			if(level[child]==0){
				level[child]=level[crrV]+1;
				q.push(child);
			}
		}
	}
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
	bfs(1);
	for(int i=1;i<=n;i++) cout<<i<<"-"<<level[i]<<endl;
}