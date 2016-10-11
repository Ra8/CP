// RMQ implementation.
// Preprosessing in O(nlogn)
// computes min(A[l..r]) in O(1)
#include <bits/stdc++.h>

using namespace std;
const int SIZE=100010;
const int MAX_LOG = int(log2(SIZE*2));
int A[SIZE];
int RMQ[SIZE][MAX_LOG];

void buildRMQ(){
	int n = SIZE;
	for(int j = 0; j < MAX_LOG; j++)
		for(int i = 0; i + (1 << j) - 1 < n ;i ++)
			RMQ[i][j] = (j ? min(RMQ[i][j-1], RMQ[i + (1 << (j -1))][j-1]): A[i]);
}
int log(int n){
	int ans=0;
	while(2<<ans <= n)ans++;
	return ans;
}
int getMin(int l, int r){
	int x = log(r-l+1);
	return min(RMQ[l][x],RMQ[r+1 - (1<<x)][x]);
}
int main(int argc, char const *argv[]){

	buildRMQ();
	int l=0,r=10;
	getMin(l,r);
}