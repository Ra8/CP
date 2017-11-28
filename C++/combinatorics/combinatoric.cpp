// Calculate binomial coefficients modulo a large base

#include <iostream>
using namespace std;
typedef long long ll;
const ll _md=1000000007;
ll _CP[1001][1001];

template<unsigned int N, ll mod>
struct FastBinom {
    ll fact[N+1];
    ll factInv[N+1];
    ll pow(ll base, ll p){
        if(p == 0) return 1;
        ll mul = 1 + (p & 1)*(base - 1);
        return pow(base*base % mod, p / 2) * mul % mod;
    }
    ll inv(ll val){
        return pow(val, mod - 2);
    } 
    FastBinom(){
        cout << "called" << endl;
        fact[0] = 1;
        factInv[0] = 1;
        for(int i = 1; i <= N; i++){
            fact[i] = fact[i - 1] * i % mod;
            factInv[i] = inv(fact[i]);
        }
    }
    ll binom(ll n, ll k){
        cout << n << " " << k << " " << N << endl;
        if(n < k) return 0;
        ll tmp = fact[n] * factInv[k] % mod;
        tmp = tmp * factInv[n - k] % mod;
        return tmp;
    }
};
long long C(int n,int k){
	if(k==n)return 1;
	if(k==0)return 1;
	if(_CP[n][k]!=-1)return _CP[n][k];
	return _CP[n][k]=(C(n-1,k)+C(n-1,k-1))%_md;
}

FastBinom<2000005, _md> B;
 
int main(int argc, char const *argv[]){
    cout << B.binom(4, 2) << endl;
    cout << B.binom(50000, 25000) << endl;    
	return 0;
}
