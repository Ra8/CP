// Greatest common divisor of two integers

#include <bits/stdc++.h>

using namespace std;

inline long long gcd(long long x, long long y) {
	while (x > 0 && y > 0){
		if (x > y){
			x %= y;
		} else {
			y %= x;
		}
	}
	return x + y;
}

int main(int argc, char const *argv[]){

	return 0;
}