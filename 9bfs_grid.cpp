#include<iostream>
#include<vector>
#include<utility>
#include <string>
#include<queue>
const int N = 1e5+10;
using namespace std;

bool vis[8][8];
int level[8][8];

int convertX(string s){
	return s[0]-'a';
}

int convertY(string s){
	return s[1]-'1';
}

vector<pair<int,int>> movements = {
	{2,-1},{2,1},
	{-2,-1},{-2,1},
	{1,2},{1,-2},
	{-1,2},{-1,-2}
};

bool isValid(int x,int y){
	return x>=0 && x<8 && y>=0 && y<8;
}

int bfs(string source, string dest){
	int sourceX = convertX(source);
	int sourceY = convertY(source);
	int destX = convertX(dest);
	int destY = convertY(dest);

	//cout<<sourceX<<sourceY<<destX<<destY<<endl;

	queue<pair<int,int>> q;
	q.push({sourceX,sourceY});
	vis[sourceX][sourceY]=true;
	//cout<<vis[sourceX][sourceY]<<endl;
	level[sourceX][sourceY]=0;

	while(!q.empty()){
		auto crrV = q.front();
		q.pop();
		int crrX = crrV.first, crrY = crrV.second;
		for(auto movement:movements){
			int childX = crrX + movement.first;
			int childY = crrY + movement.second;
			if(!isValid(childX,childY)) continue;
			if(!vis[childX][childY]){
				q.push({childX,childY});
				vis[childX][childY]=true;
				level[childX][childY]=level[crrX][crrY]+1;
			}
		}
	}

	return level[destX][destY];
}

void reset(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			vis[i][j]=0;
			level[i][j]=0;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	//t=1;
	while(t--){
		reset();
		string s1,s2;
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;
	}
}