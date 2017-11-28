// Union find data structure for disjoint set union operations
// Code adapted from bmerry

#include <bits/stdc++.h>



using namespace std;
#define SIZE 1000
// par[i] = parent of i if par[i]>=0
// par[i] = - tree size (or size of the group) if par[i]<0
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

int main(int argc, char const *argv[]){
	// initially all nodes are seperate
	// So each node is a root and each 
	// tree size is 1
	memset(par,-1,sizeof(par));

	return 0;
}
