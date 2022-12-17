#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {for (int i=0; i<v.size(); i++) {cout << v[i] << " ";}cout << "\n";}
void print(pair<int,int> p) {cout << "(" << p.first << "," << p.second << ")\n";}
void print(vector<vector<int>> vv) {for (int i=0; i<vv.size(); i++) {for (int j=0; j<vv[i].size(); j++) {cout << vv[i][j] << " ";} cout << "\n";}}
void print(vector<pair<int,int>> vp) {for (int i=0; i<vp.size(); i++){cout << "(" << vp[i].first << "," << vp[i].second << ") ";} cout << "\n";}
void print(unordered_set<int> us) {for (auto i : us) {cout << i << " ";} cout << "\n";}
void print(unordered_map<int,int> um) {for (auto i : um) {cout << i.first << ": " << i.second << "\n";}}
void print(unordered_map<int,vector<int>> um) {for (auto i : um) {cout << i.first << ": "; print(i.second);}}
