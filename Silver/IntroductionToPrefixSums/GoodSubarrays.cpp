#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
using ll = long long;

ll solve() {
    int n; cin >> n;
    string s1; cin >> s1;
    int pref[n+1];
    pref[0] = 0;
    
    for (int i = 0; i < n+1; i++) {
        pref[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        pref[i+1] = s1.at(i)+pref[i]-48;
    }
    
    unordered_map<int, ll> counts;
    
    for (int i = 0; i < n+1; i++) {
        pref[i] -= i;
        
        if (counts.find(pref[i])==counts.end()){
            counts[pref[i]]=0;
        }
        
        //cout << pref[i] << " ";
        counts[pref[i]]++;
    }
    //cout << "\n\n";
    
    ll ans = 0;
    
    for (auto const& [key, val] : counts) {
        ans += val*(val-1)/2;
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        cout << solve() << "\n";
    }
    
    return 0;
}

