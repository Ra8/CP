#include <bits/stdc++.h>

using namespace std;

const int SIZE=4096; // maximum size of graph
//adj[u][v] = # of edges from u to v
int adj[SIZE][SIZE];
// Out degree
int outE[SIZE];
// In degree
int inE[SIZE];
int color[SIZE];
vector<int> eulerPath;

// returns the starting node of the
// euler path, or -1 if no euler path exists
int checkEulerPath(){
	//init out and in degrees
	memset(outE,0,sizeof(outE));
	memset(inE,0,sizeof(inE));
	int limit=2;
	int startingPoint=-1;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			inE[j]+=adj[i][j];
			outE[i]+=adj[i][j];
		}
	}
	for(int i=0;i<SIZE;i++){
		int val = abs(outE[i]-inE[i]);
		if(val==1){
			limit--;
			if(outE[i] > inE[i]){
				startingPoint=i;
			}
		} else if(val>1){
			limit-=3;
		} else if(startingPoint==-1 && outE[i]!=0){
			startingPoint=i;
		}
	}
	if(limit<0){
		return -1;
	} else {
		return startingPoint;
	}
}

void getEulerPath(int v){
	if(color[v]==2){
		return;
	}
	color[v]=1;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<adj[v][i];j++){
			adj[v][i]--;
			j--;
			getEulerPath(i);
		}
	}
	color[v]=2;
	eulerPath.push_back(v);
}

int main(int argc, char const *argv[]){

	int res = checkEulerPath();
	if(res==-1){
		// NO Euler Path
		return 0;
	}
	getEulerPath(res);
	if(eulerPath.size()!= size needed){
		// No complete euler path
		// graph is disconnected
		return 0;	
	}
	reverse(eulerPath.begin(),eulerPath.end());
	// euler path
	return 0;
}