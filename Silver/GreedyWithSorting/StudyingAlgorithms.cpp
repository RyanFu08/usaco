#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int x; cin >> x;
    vector<int> algs;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        algs.push_back(a);
    }
    sort(algs.begin(), algs.end());
    int c = 0;
    while (x >= 0 && c < n) {
        x -= algs[c];
        c++;
    }
    
    if (c==n) {
        c++;
    }
    
    cout << c-1;

    return 0;
}
