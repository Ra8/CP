// Fast exponentiation by repeated squaring
// computes (x^y)%modulo in O(log(y)) time

#include <bits/stdc++.h>

using namespace std;

long long powMod(long long x, long long y, long long modulo){
	long long result=1;
	long long multiplier=x;
	while(y > 0){
		if(y % 2 == 1){
			result = (result * multiplier) % modulo;
		}
		y = y / 2;
		multiplier = (multiplier * multiplier) % modulo;
	}
	return result;
}

int main(int argc, char const *argv[]){

	return 0;
}