#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;

int e(int x, int y) {
    return x*100+y;
}

int main() {
    int n; cin>>n;
    int grid[n+2][n+2]; for (int i=0; i<n+2; i++) {for (int j=0; j<n+2; j++) {grid[i][j]=-1;}}
    
    
    set<int> notvis;
    for (int i=0; i<n; i++) {for (int j=0; j<n; j++) {cin>>grid[i+1][j+1]; notvis.insert(e(i+1,j+1));}}
    
    vector<vector<pair<int,int>>> ngrid;
    for (int i=0; i<n+2; i++) {ngrid.pb(vector<pair<int,int>>());for (int j=0; j<n+2; j++) {ngrid[i].pb(make_pair(0,0));}}
    
    while (!notvis.empty()) {
        int fr; for (auto i : notvis) {fr=i; break;}
        int fry=fr%100; int frx=(fr-fry)/100;
        int id=grid[frx][fry];
        vector<pair<int,int>> vis=vector<pair<int,int>>();
        queue<int> q; q.push(fr);
        
        while (!q.empty()) {
            int c=q.front(); q.pop();
            int cy=c%100; int cx=(c-cy)/100;
            if (grid[cx][cy] != id) {continue;}
            if (notvis.find(c)==notvis.end()) {continue;} notvis.erase(c);
            vis.pb(make_pair(cx,cy));
            q.push(e(cx+1,cy)); q.push(e(cx-1,cy)); q.push(e(cx,cy+1)); q.push(e(cx,cy-1));
        }
        
        int num = vis.size();
        
        for (auto pr : vis) {
            ngrid[pr.first][pr.second]=make_pair(id,num);
        }
    }
    
    for (auto vec : ngrid) {
        for (auto pr : vec) {
            cout << "(" << pr.first<<","<<pr.second << ") ";
        }
        cout<<"\n";
    }
    
    return 0;
}
