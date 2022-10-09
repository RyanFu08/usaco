#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1; cin >> s1;
    int sz = s1.size();
    short s[sz];
    for (int i = 0; i < sz; i++) {
        s[i] = s1.at(i)-48;
    }
    
    int mod[sz+1];
    mod[0] = 0;
    int tenPow = 1;
    
    int nVals[2019] = {0};
    nVals[0]++;
    
    for (int i = 1; i < sz+1; i++) {
        mod[i] = s[sz-i]*tenPow + mod[i-1];
        mod[i] %= 2019;
        tenPow *= 10;
        tenPow %= 2019;
        nVals[mod[i]]++;
    }
    
    ll count = 0;
    
    for (int i = 0; i < 2019; i++) {
        count += nVals[i]*(nVals[i]-1)/2;
    }
    cout << count;    
    
    return 0;
}
