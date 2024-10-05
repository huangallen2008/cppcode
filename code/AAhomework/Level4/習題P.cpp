#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxv=(1ll<<30);
const int high_bit=30;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
void split(map<int,int> &mp,int x) {
    auto it=mp.lower_bound(x);
    if(it->f!=x) {
        mp[x]=prev(it)->s;
    }
}
void ins(map<int,int> &mp,map<int,int> &del,int l,int r,int s) {
    split(mp,l);
    split(mp,r);
    auto it_l=mp.find(l);
    auto it_r=mp.find(r);
    for(auto it=it_l;it!=it_r;it++) {
        if(it->s<=s) {
            del[it->f]++;
            del[next(it)->f]--;
        }
    }
    it_l->s=s;
    mp.erase(next(it_l),it_r);
}
void solve() {
    map<int,int> del;
    map<int,int> mp;
    int n,k,q;
    cin>>n>>k>>q;
    mp[0]=inf,mp[n]=inf;
    del[0]=0,del[n]=0;
    REP(i,q) {
        int l,r,s;
        cin>>l>>r>>s;
        l--;
        ins(mp,del,l,r,s);
    }
    int ans=0;
    for(auto it=mp.begin();it->f!=n;it++) {
        if(it->s<inf) ans+=next(it)->f-it->f;
    }
    int p=0;
//    ope(ans)
//    for(auto [x,y]:del) cout<<x<<' '<<y<<endl;entr
    for(auto it=del.begin();it->f!=n;it++) {
        p+=it->s;
        if(p) ans-=next(it)->f-it->f;
    }
    cout<<ans<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
