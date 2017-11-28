// implementation of a Trie datastructure
#include <bits/stdc++.h>

using namespace std;

const int MAX_NUMBER_OF_NODES = 100010;
const int MAX_ASCII_CODE = 65;
int nxt =1;
//initially all numbers in x are -1
int trie[MAX_NUMBER_OF_NODES][MAX_ASCII_CODE];
// type = xy;
// 		x=1-> there is a node that ends here
// 		y=1-> there is a node that passes here
int type[MAX_NUMBER_OF_NODES];
// returns true iff a string is a substring of another
bool add(string &s){
	int v = 0;
	bool passedAFinal=false;
	for(int i=0;i<s.length();i++){
		type[v] |= 1;
		if((type[v]&2) != 0)
			passedAFinal=true;
		if(trie[v][s[i]] == -1)
			v = trie[v][s[i]] = nxt ++;
		else
			v = trie[v][s[i]];
	}

	if((type[v]&1) != 0)
		passedAFinal=true;

	type[v] |= 2;
	return (!passedAFinal);
}

void resetTrie(){
	memset(trie,-1,sizeof(trie));
	memset(type,0,sizeof(type));
	nxt=1;
}

int main(int argc, char const *argv[]){
	
}