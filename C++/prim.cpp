// Prim's algorithm for minimum spanning tree

#include <bits/stdc++.h>

using namespace std;

const int SIZE=200010; // maximum size of graph
long long d[SIZE];
int V[SIZE];//visited
long long inf = 100000000000000000;
int n; // actual size of graph
vector<pair<int, long long> > adj[SIZE];
//adj[u][i] = {vertex, weight}

long long prim(){
	long long totW=0;

	fill(d, d + n, inf);
	fill(V, V + n, 0);
	set<pair<long long,int> > s;
	for(int i = 0;i < n;i ++){
		s.insert({d[i],i});
	}
	int v;
	int j=0;
	while(!s.empty()){
		long long W=s.begin()->first;
		v = s.begin() -> second;
		if(W!=inf && V[v]==0){
			totW+=W;
			//edge to be added
		}
		V[v]=1;
		s.erase(s.begin());
		for(auto p : adj[v]){
			int u = p.first, w = p.second;
			if(d[u] > w){
				s.erase({d[u], u});
				d[u] = w;
				s.insert({d[u], u});
			}
		}
	}
	return totW;
}

int main(int argc, char const *argv[]){
	
	return 0;
}