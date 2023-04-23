//tested at https://cses.fi/problemset/hack/1648/entry/5938833/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
 
vi pow2={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776,2199023255552,4398046511104,8796093022208,17592186044416,35184372088832,70368744177664,140737488355328,281474976710656,562949953421312,1125899906842624,2251799813685248,4503599627370496,9007199254740992,18014398509481984,36028797018963968,72057594037927936,144115188075855872,288230376151711744,576460752303423488};
 
 
class SumSegTree {
    private:
        //general stuff
        int length;
        vi seg;
        //stuff to do with updating
        int setPos;
        int setVal;
        int preVal;
        //stuff to do with querying
        int ql;
        int qr;
    public:
        SumSegTree(int size) {
            length=*lower_bound(pow2.begin(),pow2.end(),size);
            seg=vi(2*length,0);
        }
        //UPDATING
        void set(int pos, int val) {
            setPos=pos;
            setVal=val;
            setHelper(1,0,length-1);
        }
        void setHelper(int cpos, int l, int r) {
            if (l==r) {
                //destination reached
                preVal=seg[cpos];
                while (cpos!=0) {
                    seg[cpos]+=setVal-preVal;
                    cpos/=2;
                }
            } else {
                int m=(l+r)/2;
                if (m>=setPos) {setHelper(2*cpos,l,m);}
                else {setHelper(2*cpos+1,m+1,r);}
            }
        }
        //QUERYING
        int rangeSum(int l, int r) {
            ql=l;
            qr=r;
            return rangeSumHelper(1,0,length-1);
        }
        int rangeSumHelper(int cpos, int l, int r) {
            if (l==r||(l>=ql&&r<=qr)) {return seg[cpos];}
            int rSum=0;
            int m=(l+r)/2;
            if (m>=ql) {rSum+=rangeSumHelper(cpos*2,l,m);}
            if (m<qr) {rSum+=rangeSumHelper(cpos*2+1,m+1,r);}
            return rSum;
        }
        void print() {
            for (auto i:seg) cout<<i<<" ";
        }
};
 
 
signed main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,q; cin>>n>>q;
    SumSegTree st(n);
    for (int i=0; i<n; i++) {
        int ai; cin>>ai;
        st.set(i,ai);
    }
    //st.print();
    while (q--) {
        int qt,a,b; cin>>qt>>a>>b;
        if (qt==1) {
            st.set(a-1,b);
        } else {
            cout<<st.rangeSum(a-1,b-1)<<"\n";
        }
    }
 
}
