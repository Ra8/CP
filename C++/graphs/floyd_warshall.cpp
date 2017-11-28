// Floyd warshal algorithm for all pairs shortest paths with negative edge weights

#include <bits/stdc++.h>

using namespace std;

const int SIZE=110; // maximum size of graph
long double d[SIZE][SIZE];
long double inf = 100000000000000000;
int n; // actual size of graph

void FloydWarshall(){
	//check init below
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
void initFloydWarshall(){
	//init for Floyd Warshall
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			d[i][j]=inf;
			if(i==j){
				d[i][j]=0;
			}
		}
	}
	//fill d[i][j] with actual weight
}

int main(int argc, char const *argv[]){
	
	return 0;
}