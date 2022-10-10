#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int k; cin >> k;
    
    int prefs[n+1]; for (int i = 0; i < n+1; i++) { prefs[i] = 0; }
    
    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        int b; cin >> b;
        prefs[a-1]++;
        prefs[b]--;
    }
    
    int sum = 0;
    
    vector<int> hs;
    
    for (int i = 0; i < n; i++) {
        sum += prefs[i];
        hs.push_back(sum);
    }
    
    sort(hs.begin(), hs.end());
    
    cout << hs[n/2];
    
    
    return 0;
}

