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
    map<int,int> mp,imp,mpt,impt;

    int an=0;
    void init() {
        mp[-inf]=0,mp[inf]=inf;
        mpt[-inf]=-inf,mpt[inf]=inf;
        imp[-inf]=0,imp[inf]=inf;
        impt[-inf]=-inf,impt[inf]=inf;
    }
    void ins(map<int,int> &mp,map<int,int> &mpt,int x,int y) {
        auto it=prev(mp.upper_bound(x));
        if(it->s>=y) return;
        mp[x]=y;
        mpt[x+y]=x;
        auto itt=mpt.find(x+y);
        it=mp.find(x);
        while(next(it)->s<=it->s) {
            mp.erase(next(it));
            mpt.erase(next(itt));
        }
    }
    int bs(map<int,int> &mp,map<int,int> &mpt,int x,int y) {
        // if(prev(mp.upper_bound(x))->s<=y) return 0;
        int l=0,r=maxv,m;
        // auto it_l=mp.begin(),it_r=prev(mp.lower_bound(x));
        auto it=prev(mpt.upper_bound(x+y));
        return min(abs(it->f-it->s-y),abs(next(it)->s-x));
    }
    void insert(int x,int y) {
        ins(mp,mpt,x,y),ins(imp,impt,y,x);
        an=max(an, max(bs(mp,mpt,x,y)>>1,bs(imp,impt,y,x)>>1));
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
        cout<<people.get_ans()<<'\n';entr
    }
    return 0;
}