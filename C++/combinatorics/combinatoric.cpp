// Calculate binomial coefficients modulo a large base

#include <bits/stdc++.h>

using namespace std;

long long _md=1000000007;
long long _CP[1001][1001];

long long C(int n,int k){
	if(k==n)return 1;
	if(k==0)return 1;
	if(_CP[n][k]!=-1)return _CP[n][k];
	return _CP[n][k]=(C(n-1,k)+C(n-1,k-1))%_md;
}

 
int main(int argc, char const *argv[]){
	memset(_CP,-1,sizeof(_CP));
	
	return 0;
}