#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10010;
int fen[MAX_N];

void update(int p,int val){
	for(int i = p;i <= MAX_N;i += i & -i)
		fen[i] += val;
}
int sum(int p){
	int ans = 0;
	for(int i = p;i;i -= i & -i)
		ans += fen[i];
	return ans;
}

int main(int argc, char const *argv[]){
	
}