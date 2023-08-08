// Problem: K - W3P1: Sequence
// Contest: Virtual Judge - 602 - Season 2023 - HW Series 1
// URL: https://vjudge.net/contest/570461#problem/K
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//numbers
using ll=long long;
#define int ll
using ld=long double;
//pairs
#define P pair
#define pi P<int,int>
#define ff first
#define ss second
#define mp make_pair
//std data structure
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
//vectors
#define V vector
#define vi V<int>
#define v2i V<vi>
#define vpi V<pi>
#define vsi V<si>
#define pb push_back
//sets
#define S set
#define MS multiset
#define US unordered_set
#define si S<int>
#define msi MS<int>
#define usi US<int>
#define ins insert
#define era erase
//maps
#define M map
#define UM unordered_map
#define mii M<int,int>
#define mivi UM<int,vi>
#define misi UM<int,si>
#define umii UM<int,int>
#define umivi UM<int,vi>
#define umisi UM<int,si>
//queues
#define Q queue
#define PQ priority_queue
#define qi Q<int>
#define qpi Q<pi>
#define pqi PQ<int>
#define rpqi PQ<int,greater<int>>
#define pqpi PQ<pi>
#define rpqpi PQ<pi,greater<pi>>
//constants
const int MOD=998244353;
const int INF=922337203685477580;
//nt functions
int binpow(int a, int b, int m=MOD) {
    a%=m; int res=1;
    while (b>0) {
        if (b&1) res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
int gcd (int a, int b) {
    return b?gcd (b,a%b):a;
}
int lcm (int a, int b) {
    return a/gcd(a,b)*b;
}
int inv(int i, int m=MOD) {
	return binpow(i, m-2, m);
}

struct segtree {
	int l;
	vi seg;
	
	segtree(int l1) {
		l=1<<((int)ceil(log2(l1)));
		seg=vi(2*l,INF);
	}
	
	int comb(int a, int b) {return min(a,b);}
	
	void set(int i, int v) {
		i=l+i; seg[i]=v; i/=2;
		while (i>0) {
			seg[i]=comb(seg[2*i],seg[2*i+1]);
			i/=2;
		}
	}
	
	int query(int li, int ri) {return qh(li,ri,1,0,l-1);}
	
	int qh(int li, int ri, int pos, int cl, int cr) {
		if (cl>ri || cr<li) {return INF;}
		if (cl>=li && cr<=ri) {return seg[pos];}
		return comb(qh(li,ri,2*pos,cl,(cl+cr)/2),qh(li,ri,2*pos+1,(cl+cr)/2+1,cr));
	}
};

void solve() {
	int n,m; cin>>n>>m;
	vi arr(n); for (int i=0; i<n; i++) cin>>arr[i];
	
	segtree dp(n+1); dp.set(0,0);
	
	vi rev;
	for (int i=0; i<n; i++) {
		
		//update relevant indices
		int tor=arr[i]; //total or so far
		vi rev1; rev1.pb(i);
		for (auto j:rev) {
			if (tor|arr[j]>tor) {rev1.pb(j);}
			tor|=arr[j];
		}
		rev=rev1; rev.pb(-1);
		
		
	}
	
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	int t; cin>>t;
	while (t--) solve();
	
	return 0;
}