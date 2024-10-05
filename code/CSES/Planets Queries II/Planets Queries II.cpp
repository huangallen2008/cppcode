#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> t(n),ind(n);
    REP(i,n) {
        cin>>t[i];
        t[i]--;
        ind[t[i]]++;
    }
    queue<int> qu;
    REP(i,n) if(ind[i]==0) qu.push(i);
    while(qu.size()) {
        int u=qu.front();
        qu.pop();
        ind[t[u]]--;
        if(ind[t[u]]==0) qu.push(t[u]);
    }
    vector<bool> inc(n);
    REP(i,n) if(ind[i]>0) inc[i]=1;
    vector<int> cid(n,-1);
    int ccnt=0;
    REP(i,n) {
        if(inc[i]&&cid[i]==-1) {
            cid[i]=ccnt;
            int x=t[i];
            while(x!=i) {
                cid[x]=ccnt;
                x=t[x];
            }
            ccnt++;
        }
    }

    return 0;
}
