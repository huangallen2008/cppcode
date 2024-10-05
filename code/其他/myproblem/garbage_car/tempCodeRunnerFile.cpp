#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define f first
#define s second
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int maxv=1e9+5;
const int inf=(1ll<<62);
struct people {
    map<int,int> mp,imp;
    int an=0;
    void init() {
        mp[-inf]=0,mp[inf]=inf;
        imp[-inf]=0,imp[inf]=inf;
    }
    void ins(map<int,int> &mp,int x,int y) {
        auto it=prev(mp.upper_bound(x));
        if(it->s>=y) return;
        mp[x]=y;
        it=mp.find(x);
        while(next(it)->s<=it->s) mp.erase(next(it));
    }
    int bs(map<int,int> &mp,int x,int y) {
        if(prev(mp.upper_bound(x))->s<=y) return 0;
        int l=0,r=maxv,m;
        auto it_l=mp.begin(),it_r=prev(mp.lower_bound(x));
        while(it_l!=it_r) {
            auto it_m=mp.lower_bound(it_l->f+it_r->f>>1);
            if(it_m==it_r) it_m=prev(it_m);
            if(y+x<=it_m->f+it_m->s) it_r=it_m;
            else it_l=next(it_m);
        }
        return min(abs(it_l->s-y),abs(next(it_l)->f-x));
    }
    void insert(int x,int y) {
        ins(mp,x,y),ins(imp,y,x);
        an=max(an, max(bs(mp,x,y)>>1,bs(imp,y,x)>>1));
    }
    int get_ans() {
        return an;
    }
} people;
signed main() {
    IOS();
    int n;
    cin>>n;
    people.init();
    while(n--) {
        int x,y;
        cin>>x>>y;
        people.insert(x,y);
        cout<<people.get_ans()<<'\n';
    }
    return 0;
}