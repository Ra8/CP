#include <bits/stdc++.h>

using namespace std;
bool isPrime(long long n){
	if(n<2)return false;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(int argc, char const *argv[]){

	return 0;
}