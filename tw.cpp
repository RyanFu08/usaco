// Problem: V - W5P3: Tree Weights
// Contest: Virtual Judge - 602 - Season 2023 - HW Series 1
// URL: https://vjudge.net/contest/570461#problem/V
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
struct tree {
	int n;
	vector<vector<int> > adj;
	vector<vector<int> > jump;
	vector<int> t1,t2; int t;
	tree() {
		
	}
	tree(vector<pair<int,int> > edges) {
		n=edges.size()+1;
		adj=vector<vector<int> >(n);
		for (auto i:edges) {
			adj[i.first].push_back(i.second);
			adj[i.second].push_back(i.first);
		}
		t1=vector<int>(n); t2=vector<int>(n);
		t=0; jump=vector<vector<int> >(n,vector<int>(ceil(log2(n))+1));
		dfs(0,0);
	}
	
	void dfs(int v, int p) {
		t1[v]=++t;
		jump[v][0]=p;
		for (int i=1; i<=ceil(log2(n)); i++) {
			jump[v][i]=jump[jump[v][i-1]][i-1];
		}
		for (auto u:adj[v]) {
			if (u!=p) dfs(u,v);
		}
		t2[v]=++t;
	}
	
	bool ancestor(int u, int v) {
		return t1[u]<=t1[v] && t2[u]>=t2[v];
	}
	
	int lca(int u, int v) {
		if (ancestor(u,v)) return u;
		if (ancestor(v,u)) return v;
		for (int i=ceil(log2(n)); i>=0; --i) {
			if (!ancestor(jump[u][i],v)) u=jump[u][i];
		}
		return jump[u][0];
	}
	
};

int n;
v2i adj;
vpi edg;
vi dst;
V<bitset<60> > dx;
tree t;

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin>>n; adj=v2i(n);
	for (int i=1; i<n; i++) {
		int u,v; cin>>u>>v; u--; v--;
		edg.pb(mp(u,v));
		adj[u].pb(v); adj[v].pb(u);
	}
	t=tree(edg);
	dst=vi(n-1); dx=V<bitset<60> >(n,bitset<60>(0));
	for (int i=0; i<n; i++) {cin>>dst[i];}
//calculate parity
	dx[1]=bitset<60>(dst[0]);
	for (int i=2; i<n; i++) {
		dx[i][0]=(2+(dst[i-1]-dx[i-1][0]))%2;
	}
	 
	for (int i=1; i<60; i++) {
		for (int j=2; j<n; j++) {
			dx[j][i]=((dst[j-1]-dx[j-1][i-1]-dx[j][i-1]+2*dx[t.lca(j-1,j)][i-1])/2-dx[j-1][i-1]+2)%2;
		}
	}
	
	for (auto i:dx) cout<<i.to_ullong()<<"\n";
	
	return 0;
}