#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (a>b) {
        swap(a,b);
    }
    if (a==0){
        return b;
    }
    return gcd(a, b%a);
}

// can make this faster by making a segment tree for log time
// sqrt time should pass tho

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int sq = sqrt(n)+1;
    
    int ns[sq*sq]; for (int i = 0; i < sq*sq; i++) {ns[i] = 0;}
    
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }
    
    //
    
    int sqgcd[sq];
    
    for (int i = 0; i < sq; i++) {
        sqgcd[i] = 0;
        for (int j = i*sq; j < i*sq+sq; j++) {
            sqgcd[i] = gcd(sqgcd[i], ns[j]);
        }
    }
    
    int best = -2147483648;
    
    for (int i = 0; i < sq; i++) {
        for (int j = i*sq; j < i*sq + sq; j++) {
            
            int cgcd = 0;
            
            for (int k = i*sq; k < i*sq + sq; k++) {
                if (k==j) {
                    continue;
                }
                cgcd = gcd(cgcd, ns[k]);
            }

            for (int k = 0; k < sq; k++) {
                if (k==i) {
                    continue;
                }
                cgcd = gcd(cgcd, sqgcd[k]);
            }
            best = max(best, cgcd);
        }
    }
    
    cout << best;
    
    return 0;
}

