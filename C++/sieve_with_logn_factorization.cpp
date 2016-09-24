#include <bits/stdc++.h>

using namespace std;

const int maxN=10000010;
int primes[maxN];
long long countt[maxN];

void sieve(){
	//save smallest prime factor in primes[i]
	for(int i=2;i<maxN;i++){
		primes[i]=i;
	}
	for(long long i=2;i*i<maxN;i++){
		if(primes[i]==i){
			for(long long j=i;j<maxN;j+=i){
				if(primes[j]==j)
					primes[j]=i;
			}
		}
	}
}
// You can now compute the factors of n in O(log n) instead of O(sqrt(n))
void factorN(int n){
	int prime=0;
	while(n!=1){
		prime=primes[n];
		cout << prime << endl;
		n=n/prime;
	}
}

int main(int argc, char const *argv[]){

	return 0;
}