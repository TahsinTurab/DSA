#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
#define el "\n"
#define ll long long
#define ull unsigned long long
#define M 10000007
using namespace std;
//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

//Taking the input of graph
const int N = 1e5+10;
std::vector<int> graph[N+1];
set<int>nodes;

void inputGraph(int vertex,int edge){
    
    for(int i=0;i<edge;i++){
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        nodes.insert(v1);
        nodes.insert(v2);
    }
}


//DFS [O(V+E)]
bool vis[N+1];


bool dfs(int vertex, int parent){

    // Take action after entering the vertex

    vis[vertex]=true;
    bool isLoopExists = false;
    for(auto child:graph[vertex]){
        // Take action before entering a child
        if(vis[child]==true && child==parent) {
            //ans=true;
            continue;
        }
        if(vis[child]) return true;
        
        isLoopExists |= dfs(child,vertex);
        //Take action after exiting a child
    }
    //Take action on vertex before exiting

    return isLoopExists;
}


void solve()
{
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin>>t;
    
    while(t--){
        int vertex=1,edge=1;
        cin>>vertex>>edge;
        int cc=0;
        bool ans=false;
        //bool ans = false;
        inputGraph(vertex,edge);
        for(int node=1;node<=vertex;node++){
            if(vis[node]) continue;
            else ans |= dfs(node,0);
        }
        cout<<ans<<el;

    }
}