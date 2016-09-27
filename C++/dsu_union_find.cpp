#include <bits/stdc++.h>

// Code adapted from bmerry

using namespace std;
int SIZE=1000;

int par[SIZE];

int root(int v){
	return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void merge(int x, int y) {	//	x and y are vertices
	if((x = root(x)) == (y = root(y))
		return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

int main(int argc, char const *argv[]){
	memset(par,-1,sizeof(par));
	
	return 0;
}
