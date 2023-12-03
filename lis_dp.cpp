#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int cnt[N];

int lis(int idx, int *arr){
	if(cnt[idx]!=-1) return cnt[idx];
	int ans=1;
	for(int i=0;i<idx;i++){
		if(arr[idx]>arr[i])
			ans = max(ans,lis(i,arr)+1);
	}
	return cnt[idx]=ans;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) cnt[i]=-1;
	int ans=0;
	for(int i=0;i<n;i++) ans = max(ans, lis(i,arr));
	cout<<ans<<endl;
}