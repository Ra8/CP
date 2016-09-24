#include <bits/stdc++.h>

using namespace std;

long double toD(long double a){
	long double PI=acos(0)*2.0;
	return a*180.0/PI;
}
// returns the angle the segment (0,0) to (x,y) makes with the y axis
long double getA(int x, int y){
	long double ans=toD(atan2(x,y));
	if(ans<0)ans+=360.0;
	return ans;
}

int main(int argc, char const *argv[]){
	return 0;
}