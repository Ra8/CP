// Bellman Ford algorithm for single source shortest paths with negative edge weights

#include <bits/stdc++.h>

using namespace std;

const int SIZE=1010; // maximum size of graph
long long d[SIZE];
long long inf = 100000000000000000;
int n; // actual size of graph
vector<pair<int, long long> > adj[SIZE];
//adj[u][i] = {vertex, weight}

bool BellmanFord(int v){
	bool negativeLoop=false;
	for(int i=0;i<SIZE;i++){
		d[i]=inf;
	}
	d[0]=1;
	for(int i=0;i<n;i++){
		//The next two loops is looping over all edges
		for(int j=0;j<n;j++){
			for(int k=0;k<adj[j].size();k++){
				int source=j;
				int target=adj[j][k].first;
				int weight=adj[j][k].second;
				if(d[source]+weight < d[target]){
					d[target] = d[source]+weight;
					if(i==n-1){
						negativeLoop=true; // Negative loop found
					}
				}
			}
		}
	}
	return negativeLoop;
}

int main(int argc, char const *argv[]){
	
	return 0;
}