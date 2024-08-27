#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define f first
#define s second
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int maxv=1e9+5;
const int inf=(1ll<<62);
struct people {
    map<int,int> mp,imp,mpt,impt;
    int dis(int x1,int y1,int x2,int y2) {
        return max(abs(x1-x2),abs(y1-y2));
    }
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
            mpt.erase(next(it)->f+next(it)->s);
            mp.erase(next(it));
        }
    }
    int bs(map<int,int> &mp,map<int,int> &mpt,int x,int y) {
        if(prev(mp.upper_bound(x))->s<=y) return 0;
        auto it=prev(mpt.upper_bound(x+y));
        return min(dis(x,y,it->s,it->f-it->s),dis(x,y,next(it)->s,next(it)->f-next(it)->s))+1;
    }
    void insert(int x,int y) {
        ins(mp,mpt,x,y);
        ins(imp,impt,y,x);
        an=max(an,max(bs(mp,mpt,x,y)>>1,bs(imp,impt,y,x)>>1));
    }
    int get_ans() {
        return an;
    }
} people;
signed main() {
    IOS();
    int h,w,n;
    cin>>h>>w>>n;
    people.init();
    while(n--) {
        int x,y;
        cin>>x>>y;
        people.insert(x,y);
        cout<<people.get_ans()<<'\n';
    }
    return 0;
}