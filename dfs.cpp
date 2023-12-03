#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex){
	//cout<<vertex<<endl;
	vis[vertex]=true;
	for(auto &child:graph[vertex]){
		//cout<<"Par: "<<vertex<<" child:"<<child<<endl;
		if(vis[child]) continue;
		dfs(child);
	}
}

int main()
{
	int node,edge;
	cin>>node>>edge;
	for(int i=0;i<edge;i++){
		int v1,v2;
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	dfs(1);

}

//TC: O(verties+edge)
//MC: 