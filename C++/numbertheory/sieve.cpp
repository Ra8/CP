// Sieve method to determine primality of all numbers <= maxN

#include <bits/stdc++.h>

using namespace std;

const int maxN=50000001;

int primes[maxN];
/*
After calling sieve()
For all i < maxN
prime[i] = 1 iff i is prime
prime[i] = 0 iff i is composite
*/
void sieve(){
	for(int i=2;i<maxN;i++){
		primes[i]=1;
	}
	for(long long i=2;i*i<maxN;i++){
		if(primes[i]==1){
			for(long long j=i*i;j<maxN;j+=i){
				primes[j]=0;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	sieve();
	return 0;
}