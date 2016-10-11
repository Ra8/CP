// Addition and multiplication of integers represented as strings

#include <iostream>
#include <algorithm>

using namespace std;

string add(string s1, string s2){
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	while(s1.length()!=s2.length()){
		if(s1.length()<s2.length()){
			s1.push_back('0');
		} else {
			s2.push_back('0');
		}
	}
	s1.push_back('0');
	s2.push_back('0');
	int carry=0;
	string s3="";
	for(int i=0;i<s1.length();i++){
		int sum=carry+s1[i]+s2[i]-'0'-'0';
		carry=sum/10;
		int digit=sum%10;
		if(!(i==s1.length()-1 && digit==0))
		s3.push_back(char(digit+'0'));
	}
	reverse(s3.begin(),s3.end());
	return s3;
}
string multiply(string s1, string s2){
	string multiplyersOfS1[10]={"0",s1};
	for(int i=2;i<10;i++){
		multiplyersOfS1[i]=add(multiplyersOfS1[i-1],s1);
	}
	string result="0";
	string extraZeroes="";
	for(int i=s2.length()-1;i>=0;i--){
		result=add(result,multiplyersOfS1[s2[i]-'0']+extraZeroes);
		extraZeroes.push_back('0');
	}
	return result;
}

int main(){
	cout << add("9999","9") << endl;
	cout << multiply("31268","32879") << endl;
	return 0;
}