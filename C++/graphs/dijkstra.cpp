// Dijkstra's algorithm for single source shortest paths with non negative weights

#include <bits/stdc++.h>

using namespace std;

long long d[100010];
int parent[100010]; // for parents
long long inf = 100000000000000000;
vector<pair<int, long long> > adj[100010];
//adj[u][i] = {vertex, weight}
int n; // number of verticies
int m; // number of edges

void dijkstra(int v){
	fill(d, d+n+10, inf);
	d[v] = 0;
	int u;
	set<pair<long long,int> > s;
	s.insert({d[v], v});
	while(!s.empty()) {
		u = s.begin()->second;
		s.erase(s.begin());
		for(int i=0;i<adj[u].size();i++) {
			pair<int, long long> p = adj[u][i];
			if(d[p.first] > d[u] + p.second){
				s.erase({d[p.first], p.first});
				d[p.first] = d[u] + p.second;
				s.insert({d[p.first], p.first});
				parent[p.first]=u; // for parents
			}
		}
	}
}

vector<int> getPath(int s, int t){
	int u=t;
	vector<int> path;
	while(u!=s){
		path.push_back(u);
		u=parent[u];
	}
	path.push_back(s);
	reverse(path.begin(), path.end());
	return path;
}

int main(){
	
	return 0;
}