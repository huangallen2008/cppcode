#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define f first
#define s second
#define pii pair<int,int>
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define Vi vector<int>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<x<<", "<<flush;
#define ope(x) cout<<(#x)<<"="<<x<<endl;
#define oparr(x) cout<<(#x)<<": ";for(auto allen:(x)) cout<<allen<<' ';cout<<"sz="<<SZ(x)<<endl;
#define entr cout<<endl;
#endif // LOCAL
const int inf=(1ll<<62);
signed main () {
    IOS();
    int n,m;
    cin>>n>>m;
    Vi w(n);
    REP(i,n) cin>>w[i];
    vector<Vi> p(m);
    Vi k(m);
    REP(i,m) {
        cin>>k[i];
        p[i]=Vi(k[i]);
        REP(j,k[i]) cin>>p[i][j],p[i][j]--;
    }
    vector<multiset<pii>> a(m);
    Vi sum(m);
    REP(i,m) {
        for(int x:p[i]) a[i].insert({w[x],x}),sum[i]+=w[x];
    }
//    oparr(sum)
    auto mnit=min_element(ALL(sum));
    int mns=*mnit,mnid=0;
    REP(i,m) if(sum[i]==mns) {
        mnid=i;
        break;
    }
    Vi an;
    priority_queue<pii> pq;
    REP(i,m) {
        auto it=a[i].upper_bound({sum[i]-mns,inf});
        if(it==a[i].end()) {
            cout<<"-1\n";
            return 0;
        }
        int val=sum[i]-it->f;
        pq.push({val,i});
    }
    REP(rr,n) {
        auto [vl,id]=pq.top();
        pq.pop();
        int val=sum[id]-vl;
        a[id].erase(a[id].lower_bound({val,-inf}));
        sum[id]=vl;
        mns=vl;
        if(a[id].size())pq.push({vl-a[id].begin()->f,id});
    }
    reverse(ALL(an));
    for(int x:an) cout<<x+1<<' ';cout<<'\n';
    return 0;
}
