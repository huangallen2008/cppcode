#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
Graph gb;
vector<bool> inc;
vector<int> d;
void dfs(int u) {
    for(int v:gb[u]) {
        if(inc[v]) continue;
        d[v]=d[u]+1;
//        op(v) op(u) op(d[v]) ope(d[u])
        dfs(v);
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    queue<int> q;
    gb=Graph(n);
    d=vector<int>(n,-1);
    vector<int> t(n),ind(n);
    REP(i,n) {
        cin>>t[i];
        t[i]--;
        gb[t[i]].pb(i);
        ind[t[i]]++;
    }
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        ind[t[u]]--;
        if(ind[t[u]]==0) q.push(t[u]);
    }
    inc=vector<bool>(n);
    REP(i,n) if(ind[i]>0) inc[i]=1;
    vector<int> cid(n,-1),csz;
    int ccnt=0;
    REP(i,n) {
        if(inc[i]&&cid[i]==-1) {
            cid[i]=ccnt;
            int x=t[i];
            int cnt=1;
            while(x!=i) {
                cid[x]=ccnt;
                x=t[x];
                cnt++;
            }
            ccnt++;
            csz.pb(cnt);
        }
    }
//    cout<<"csz:";REP(i,csz.size()) cout<<csz[i]<<" ";cout<<endl;
//    cout<<"cid:";REP(i,n) cout<<cid[i]<<" ";cout<<endl;
//    cout<<"inc:";REP(i,n) cout<<inc[i]<<" ";cout<<endl;
//    REP(i,n) if(cid[i]!=-1) d[i]=csz[i];
    REP(i,n) {
        if(inc[i]) {
            d[i]=csz[cid[i]];
//            op(i) ope(d[i])
            dfs(i);
        }
//        cout<<"end"<<endl;
    }
    REP(i,n) cout<<d[i]<<" ";
    cout<<"\n";
    return 0;
}
