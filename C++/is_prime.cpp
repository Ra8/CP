#include <bits/stdc++.h>

using namespace std;
bool isPrime(long long n){
	if(n<2)return false;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(long long i=5;i*i<=n;i += 6){
		if(n%i==0)return false;
		if(n % (i + 2) == 0) return false;
	}
	return true;
}

bool isPrime2(long long n){
	if(n<2)return false;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(int argc, char const *argv[]){
    
	return 0;
}