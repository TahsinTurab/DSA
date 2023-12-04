#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Node{
public:
	int val;
	Node *next;
	Node(){
		val=0;
		next=NULL;
	}
	Node(int v, Node *n){
		val=v;
		next=n;
	}
};

int main()
{
	int n;
	cin>>n;
	int arr[n];
	auto dHead = new Node();
	auto crrNode = dHead;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		auto newNode = new Node(arr[i],NULL);
		crrNode->next = newNode;
		crrNode=newNode;
	}

	auto head = dHead->next;
	auto frontNode = head->next;
	auto presNode = head;
	auto pastNode = new Node();
	while(frontNode!=NULL){
		frontNode = presNode->next;
		presNode->next = 
	}

}