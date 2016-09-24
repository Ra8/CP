#include <bits/stdc++.h>

using namespace std;

string toString(long long n){
	string s="";
	bool isNegative=(n<0);
	if(n==0){
		return "0";
	}
	if(n<0){
		n=n*-1;
	}
	while(n){
		int digit=n%10;
		n=n/10;
		s=char(digit+'0')+s;
	}
	if(isNegative){
		s="-"+s;
	}
	return s;
}

long long toLL(string s){
	int start=0;
	long long ans=0;
	bool isNegative=false;
	if(s[start]=='-'){
		start++;
		isNegative=true;
	}
	for(int i=start;i<s.length();i++){
		int digit=s[i]-'0';
		ans=ans*10+digit;
	}
	if(isNegative){
		ans=ans*-1;
	}
	return ans;
}

int main(int argc, char const *argv[]){

	return 0;
}