#include <bits/stdc++.h>
using namespace std;

struct ph {inline size_t operator()(const pair<int,int> & v) const {return v.first*31+v.second;}};

int main() {
    unordered_set<pair<int,int>, ph> hashset;
    return 0;
}
