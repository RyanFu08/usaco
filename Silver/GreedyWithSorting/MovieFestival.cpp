#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

int main() {
    int n; cin >> n;
    
    vector< pair <int,int> > movies;
    
    for (int i = 0; i < n; i++) {
        int a; cin >> a; int b; cin >> b;
        movies.push_back(make_pair(a,b));
    }
    
    sort(movies.begin(), movies.end(), sortbysec);

    int c = 0;
    int prev = -1;
    
    for (int i = 0; i < n; i++) {
        if (movies[i].first >= prev) {
            c++;
            prev = movies[i].second;
        }
    }

    cout << c;

    return 0;
}
