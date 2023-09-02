// Problem: E. Maximum Monogonosity
// Contest: Codeforces - Codeforces Round 892 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1859/E
// Memory Limit: 512 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
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
#define v3i V<v2i>
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
#define rpqi PQ<int,vi,greater<int> >
#define pqpi PQ<pi>
#define rpqpi PQ<pi,vpi,greater<pi> >
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
//new header wip

void solve() {
	int n,k; cin>>n>>k;
	vi a(n);
	for (int i=0; i<n; i++) {
		cin>>a[i];
	}
	vi b(n);
	for (int i=0; i<n; i++) {
		cin>>b[i];
	}
	v2i dp(n+1,vi(n+1,-INF));
	dp[0][0]=0;
	for (int i=0; i<n; i++) {
		
	}
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin>>t;
	while (t--) solve();
	return 0;
}
