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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> p(n),q(n);
    vector<bool> in1(n),in2(n);//in1[i] p[i] is in ,in2[i] q[i] is in
    vector<int> isin(n);//isin[i]:index i is in
    REP(i,n) {
        cin>>p[i];
        p[i]--;
    }
    int x,y;
    cin>>x;
    REP(i,n) {
        char c;
        cin>>c;
        if(c=='1') {
            in1[i]=1;
            isin[p[i]]=1;
        }
    }
    REP(i,n) {
        cin>>q[i];
        q[i]--;
    }
    cin>>y;
    REP(i,n) {
        char c;
        cin>>c;
        if(c=='1') {
            in2[i]=1;
            isin[q[i]]=2;
        }
    }
//    oparr(isin)
    vector<bool> isr(n);// right?
    priority_queue<int,vector<int>,greater<int>> tw;//two times
    vector<int> cnt(n);//count now numbers of times
    REP(i,n) {
        if(!isin[i]) isr[i]=1;
    }
    REP(i,x) {
        cnt[p[i]]++;
        if(in1[i]) isr[p[i]]=1;
        if(!isin[p[i]]) {
            cout<<"-1\n";
            return 0;
        }
    }
    REP(i,y) {
        cnt[q[i]]++;
        if(in2[i]) isr[q[i]]=1;
        if(!isin[q[i]]) {
            cout<<"-1\n";
            return 0;
        }
        if(cnt[q[i]]==2) {
            tw.push(q[i]);
        }
    }
    vector<int> order;
    int it1=x,it2=y;
    while(tw.size()) {
        int u=tw.top();
        tw.pop();
        cnt[u]--;
        order.pb(u);
        if(isin[u]==2) {
            cnt[p[it1]]++;
            if(in1[it1]) isr[p[it1]]=1;
            if(!isin[p[it1]]) {
                cout<<"-1\n";
                return 0;
            }
            if(cnt[p[it1]]==2) tw.push(p[it1]);
            it1++;
        }
        else {
            cnt[q[it2]]++;
            if(in2[it2]) isr[q[it2]]=1;
            if(!isin[q[it2]]) {
                cout<<"-1\n";
                return 0;
            }
            if(cnt[q[it2]]==2) tw.push(q[it2]);
            it2++;
        }
    }
//    oparr(isr)
    bool ok=1;
    REP(i,n) {
        if(!isr[i]) {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<order.size()<<'\n';
    for(int x:order) cout<<x+1<<' ';
    cout<<'\n';
    return 0;
}
