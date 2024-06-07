#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define ll long long
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
bool ok=1;
void split(map<int,int> &mp,int x) {
    auto it=mp.lower_bound(x);
    if(it->f!=x) {
        mp[x]=prev(it)->s;
    }
}
void ins(map<int,int> &mp,int l,int r) {
    r++;
    int sum=0;
    split(mp,l);
    auto it_l=mp.find(l);
    split(mp,r);
    auto it_r=mp.find(r);
    for(auto it=it_l;it!=it_r;it++) {
        if(it->s) sum+=next(it)->f-it->f;
    }
    int v=1;
    if(!(r-l&1)&&sum==(r-l)>>1) {
        ok=0;
        return;
    }
    if(sum<=(r-l-1)>>1) v=0;
    it_l->s=v;
    mp.erase(next(it_l),it_r);
}
void solve() {
    ok=1;
    int n,q;
    cin>>n>>q;
    string s,f;
    cin>>s>>f;
    vector<int> l(q),r(q);
    REP(i,q) {
        cin>>l[i]>>r[i];
        l[i]--,r[i]--;
    }
    reverse(ALL(l));
    reverse(ALL(r));
    map<int,int> mp;
    mp[0]=f[0]=='1';
    REP1(i,n-1) {
        if(f[i]!=f[i-1]) mp[i]=f[i]=='1';
    }
    mp[n]=0;
    REP(i,q) {
        ins(mp,l[i],r[i]);
        if(!ok) {
            cout<<"NO\n";
            return;
        }
    }
    vector<int> ss(n+1);
    RREP(i,n) ss[i]=ss[i+1]+(s[i]=='1');
    for(auto it=mp.begin();it->f!=n;it++) {
        if(it->s) {
            int len=next(it)->f-it->f;
            if(ss[it->f]-ss[next(it)->f]!=len) {
                cout<<"NO\n";
                return;
            }
        }
        else {
            if(ss[it->f]-ss[next(it)->f]!=0) {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
