#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
struct Mos {
    map<int,int> mp;
    void init() {
        mp.clear();
        mp[-inf]=0,mp[inf]=inf;
    }
    void ins(int x,int y) {
        auto it=prev(mp.upper_bound(x));
        if(it->s>=y) return;
        mp[x]=y;
        it=mp.find(x);
        while(next(it)->s<=it->s) {
            mp.erase(next(it));
        }
    }
    int qu(int k) {
        auto it=prev(mp.upper_bound(x));
        return it->s;
    }
} ;
int main() {
    int n,q;
    cin>>n>>q;
    vector<Mos> m(n);
    REP(i,n) m[i].init();
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            
        }
    }
    return 0;
}