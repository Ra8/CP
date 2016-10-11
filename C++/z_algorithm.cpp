#include <bits/stdc++.h>

using namespace std;
const int SIZE = 2000010;
int z[SIZE];
// z[i] = k -> s[0+j]=s[i+j]  for all j<k
void zAlgo(string& s){
	int n=s.length();
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R-L] == s[R]) R++;
			z[i] = R-L;
			R--;
		} else {
			int k = i-L;
			if (z[k] < R-i+1){
				z[i] = z[k];
			} else {
				L = i;
				while (R < n && s[R-L] == s[R]) R++;
				z[i] = R-L;
				R--;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	
}