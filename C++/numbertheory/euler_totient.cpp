// Euler's totient function, compute how many numbers less than n are relatively prime to n

#include <bits/stdc++.h>

using namespace std;

long long phi(long long n){
	long long ans=n;
	long long last=0;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0){
			n/=i;
			if(n%i!=0){
				ans=ans/i*(i-1);
				last=i;
			}
			i--;
		}
	}
	if(n!=1 && n!=last){
		ans=ans/n*(n-1);
	}
	return ans;
}

int main(int argc, char const *argv[]){

	return 0;
}