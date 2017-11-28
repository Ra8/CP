// topological sort using DFS end time.
// also computes start and end time of DFS travel

#include <bits/stdc++.h>

using namespace std;

const int SIZE=10010; // maximum size of graph
vector<int> adj[SIZE];
//adj[u][i] = edge from u -> adj[u][i]
int startT[SIZE];
int endT[SIZE];
int color[SIZE];
vector<int> topoOrder;


int TIME=0;
//returns false if there is a cycle
bool dfs(int v){
	startT[v]=TIME++;
	color[v]=1;
	bool isOk=true;
	for(int i=0;i<adj[v].size();i++){
		if(color[adj[v][i]] == 0){
			isOk &= dfs(adj[v][i]);
		} else if(color[adj[v][i]]==1){
			isOk = false;
		}
	}
	color[v]=2;
	endT[v]=TIME++;
	topoOrder.push_back(v);
	return isOk;
}
// fills topoOrder with the topological order
// returns true if a topological order exists
// false otherwise
bool getTopoOrder(){
	int inD[SIZE];
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<adj[i].size();j++){
			inD[adj[i][j]]++;
		}
	}
	bool isOk=true;
	for(int i=0;i<SIZE;i++){
		// Make sure that i is a node
		// with in Degree 0
		// pay attention to nodes with in and out Degree 0
		if(inD[i]==0 && adj[i].size()>0){
			isOk &= dfs(i);
		}
	}
	reverse(topoOrder.begin(),topoOrder.end());
	return (isOk && (topoOrder.size()==27));
}

int main(int argc, char const *argv[]){
	if(getTopoOrder()){
		for(int i=0;i<topoOrder.size();i++){
			cout << topoOrder[i];
		}
	}
	return 0;
}