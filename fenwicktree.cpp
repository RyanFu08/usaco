#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

template <typename TYPE>
class FenwickTree {
    // 0-indexed Fenwick Tree with range update??
    private:
        TYPE * add;TYPE * mul;size_t length;
        void range_update_helper(size_t pos, TYPE mulfact, TYPE addfact){pos += 1;while(pos <= length){mul[pos - 1] += mulfact;add[pos - 1] += addfact;pos += pos & -pos;}}
    public:
        //constructors
        FenwickTree(std::vector<TYPE>& v){length = v.size();add = new TYPE[length];mul = new TYPE[length];for(size_t i = 0; i < length; ++i){add[i] = 0;mul[i] = 0;}for(size_t i = 0; i < length; ++i){point_update(i, v[i]);}}
        FenwickTree(TYPE v[], int input_length){length = input_length;add = new TYPE[length];mul = new TYPE[length];for(size_t i = 0; i < length; ++i){add[i] = 0;mul[i] = 0;}for(size_t i = 0; i < length; ++i){point_update(i, v[i]);}}
        void point_update(size_t i, TYPE val){range_update(i, i, val);}
        void range_update(size_t i, size_t j, TYPE val){if(i < 0 or j < i or j >= length){throw std::invalid_argument("subarray range invalid.");}else{range_update_helper(i, val, -val * ((TYPE) i - 1));range_update_helper(j, -val, val * j);}}
        TYPE range_sum(size_t i, size_t j){if(i < 0 or j < i or j >= length){throw std::invalid_argument("subarray range invalid.");}else{if(i > 0){return prefix_sum(j) - prefix_sum(i - 1);}else{return prefix_sum(j);}}}
        TYPE prefix_sum(size_t i){TYPE mulfact = 0;TYPE addfact = 0;size_t startindex = i;i += 1;while(i > 0){addfact += add[i - 1];mulfact += mul[i - 1];i = i & (i - 1);}return ((TYPE) startindex) * mulfact + addfact;}
        TYPE point_sum(size_t i){if(i < 0 or i >= length){throw std::invalid_argument("invalid array index.");}else{return range_sum(i, i);}}
};

int main() {
    vector<int> v = {1,2,3,4,5};
    FenwickTree fwt(v);
    cout << fwt.range_sum(0,4) << endl; //15
    fwt.point_update(0,10);
    cout << fwt.range_sum(0,4) << endl; //25
    cout << fwt.point_sum(0) << endl; //11
}
