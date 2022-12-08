//binary search demo

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;
using ll = long long;

int main() {
    
    vector<int> v = {1,3,5,7,9,13,15,17,19,21,23,25,27,29};
    
    //find first number not less than 5
    int lo = 0;
    int hi = v.size()-1;
    int mid;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        if (v[mid] < 5) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    cout << lo << "\n";
    
    //find the first number less than or equal to 13
    lo = 0; 
    hi = v.size()-1;
    while (lo <= hi) {
        mid = (lo+hi)/2;
        if (v[mid] <= 13) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    cout << hi << "\n";
    
    return 0;
}
