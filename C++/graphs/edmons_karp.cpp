// Edmonds–Karp algorithm for maximum flow algorithm
#include <bits/stdc++.h>

using namespace std;

const int SIZE=1000;
// Capacity matrix
int C[SIZE][SIZE];

// Adjacency matrix
int E[SIZE][SIZE];

// Current Flow
int F[SIZE][SIZE];

//Parent in BFS
int P[SIZE];

// Capacity of path found
int M[SIZE];

int BFS(int s, int e){
	memset(P,-1,sizeof(P));
	M[s]=100000010;//infinity
	P[s]=-2;
	queue<int> q;
	q.push(s);
	while(q.size()>0){
		int node=q.front();
		q.pop();
		if(node==e)continue;
		for(int i=0;i<SIZE;i++){
			if(E[node][i]==1 && P[i]==-1 && C[node][i]-F[node][i]>0){
				P[i]=node;
				M[i]=min(M[node], C[node][i]-F[node][i]);
				if(i!=e){
					q.push(i);
				} else {
					return M[e];
				}
			}
		}
	}
	if(P[e]==-1)
		return 0;
	return M[e];
}
// Edmonds–Karp algorithm for Max-flow
int ES(int source, int sink){
	// f is the max flow size
	int f=0;
	while(true){
		int m=BFS(source,sink);
		if(m==0)break;
		f+=m;
		int node=sink;
		while(node!=source){
			int node2=P[node];
			F[node2][node]+=m;
			F[node][node2]-=m;
			node=node2;
		}
	}
	return f;
}


int main(int argc, char const *argv[]){
	// We should fill in E and C
	// to the edges and corresponding capacities
	cout << ES(source,sink) << endl;
	return 0;
}