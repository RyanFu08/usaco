#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ins insert
using namespace std;
using ll = long long;

ll l;
vector<pair<ll,ll>> goto1;
vector<pair<ll,ll>> goto2;
vector<ll> pow2;

vector<pair<ll,ll>> result1;
multiset<pair<ll,ll>> result2;

vector<bool> toBinArr(ll x) {
    vector<bool> ret;
    for (int i=l-1; i>=0; i--) {
        if (x>=pow2[i]) {
            ret.pb(true);
            x-=pow2[i];
        } else {
            ret.pb(false);
        }
    }
    return ret;
}


int main() {
    ll n; cin>>n;
    ll xg; ll yg; cin>>xg>>yg;
    
    if (n%2==0) {
        l=n/2;
        for (ll i=0; i<l; i++) {
            ll xi; ll yi; cin>>xi>>yi;
            goto1.pb(mp(xi,yi));
        }
        for (ll i=0; i<l; i++) {
            ll xi; ll yi; cin>>xi>>yi;
            goto2.pb(mp(xi,yi));
        }}
    if (n%2==1) {
        l=n/2+1;

        for (ll i=0; i<l; i++) {
            ll xi; ll yi; cin>>xi>>yi;
            goto1.pb(mp(xi,yi));
        }
        for (ll i=0; i<l-1; i++) {
            ll xi; ll yi; cin>>xi>>yi;
            goto2.pb(mp(xi,yi));
        }
        goto2.pb(mp(9223372085775807,9223372085775807));
    }
    pow2.pb(1);
    for (int i=1; i<n+1; i++) {
        pow2.pb(pow2[i-1]*2);
    }
    
    for (int i=0; i<pow2[l]; i++) {
        vector<bool> br = toBinArr(i);
        for (auto a : br) {
            cout<<a;
        }
        cout<<"\n";
        pair<ll,ll> rs=mp(0,0);
        for (int j=0; j<l; j++) {
            if (br[j]) {
                rs.first+=goto1[j].first;
                rs.second+=goto1[j].second;
            }
        }
        result1.pb(rs);
    }
    for (int i=0; i<pow2[l]; i++) {
        vector<bool> br = toBinArr(i);
        pair<ll,ll> rs=mp(xg,yg);
        for (int j=0; j<l; j++) {
            if (br[j]) {
                rs.first-=goto1[j].first;
                rs.second-=goto1[j].second;
            }
        }
        result2.ins(rs);
    }
    ll tot=0;
    for (auto pr : result2) {
        tot+=result2.count(pr);
        cout<<pr.first<<" "<<pr.second<<"\n";
    }
    cout<<tot;
    return 0;
}
