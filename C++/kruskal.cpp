#include <bits/stdc++.h>

using namespace std;

const int SIZE=200010; // maximum size of graph
int n; // actual size of graph
int m; // number of edges
vector<pair<int, long long> > adj[SIZE];
//adj[u][i] = {vertex, weight}

int par[SIZE];

int root(int v){
	return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void merge(int x, int y) {	//	x and y are vertices
	if((x = root(x)) == (y = root(y)))
		return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

class Edge{
public:
	int s,t;
	long long w;
};
bool cmp(Edge e1, Edge e2){
	return e1.w<e2.w;
}
long long Kruskal(){
	long long totW=0;
	//Setup for DSU
	memset(par,-1,sizeof(par));
	vector<Edge> edges;
	for(int i=0;i<n;i++){
		for(int j=0;j<adj[i].size();j++){
			// make sure only 1 of the two edges
			// are added in an undirected graph
			if(adj[i][j].first>i){
				Edge e;
				e.s=i;
				e.t=adj[i][j].first;
				e.w=adj[i][j].second;
				edges.push_back(e);
			}
		}
	}
	sort(edges.begin(),edges.end(),cmp);

	for(int i=0;i<edges.size();i++){
		if(root(edges[i].s) != root(edges[i].t)){
			//Add the new edge
			merge(edges[i].s,edges[i].t);
			totW+=edges[i].w;
		}
	}
	return totW;
}

int main(int argc, char const *argv[]){
	
	return 0;
}