// Segment trees with lazy propagation
// Code adapted from Al.Cash
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;  // limit for array size
int n;  // array size
// segment tree
long long t[2 * N];
// height
int h = 0;
// lazy propagation
long long d[N];

void calc(int p, long long k) {
	if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
	else t[p] = t[p<<1] + t[p<<1|1] + d[p] * k; // t[p] = d[p]*k
}

void apply(int p, long long value, long long k) {
	t[p] += value * k; // = instead of +=
	if (p < n) d[p] += value; // = instead of +=
}

void build(int l, int r) {
	int k = 2;
	for (l += n, r += n-1; l > 1; k <<= 1) {
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; --i) calc(i, k);
	}
}

void push(int l, int r) {
	int s = h, k = 1 << (h-1);
	for (l += n, r += n-1; s > 0; --s, k >>= 1)
	for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
		apply(i<<1, d[i], k);
		apply(i<<1|1, d[i], k);
		d[i] = 0;
	}
}

void modify(int l, int r, long long value) {
	if (value == 0) return;
	push(l, l + 1);
	push(r - 1, r);
	int l0 = l, r0 = r, k = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
		if (l&1) apply(l++, value, k);
		if (r&1) apply(--r, value, k);
	}
	build(l0, l0 + 1);
	build(r0 - 1, r0);
}

long long query(int l, int r) {
	push(l, l + 1);
	push(r - 1, r);
	long long res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += t[l++];
		if (r&1) res += t[--r];
	}
	return res;
}

int main() {
	memset(t,0,sizeof(t));
	memset(d,0,sizeof(d));
	n = actual size;
	h = sizeof(int) * 8 - __builtin_clz(n);
	for(int i=0;i<n;i++){
		cin >> t[i+n]; // input on the ith element of the array
	}
	int l,r,v;
	build(l,r); // build changes [l,r)
	modify(l,r,v); // modify [l,r)
	query(l,r); // get the answer for [l,r)
	push(l,r); // apply the lazy propagation to [l,r)
	return 0;
}


