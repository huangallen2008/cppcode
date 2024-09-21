#include<bits/stdc++.h>
using namespace std;
#define L int16_t
#define I int
#define REP(i,n) for(I i=0;i<(n);i++)
#define P push_back
#define Graph vector<vector<I>>
const I X=666666,M=1e9+9;
L f(Graph &g,I u,I fa) {
    L r=X;
    for(I v:g[u]) {
        if(v==fa) continue;
        r=r*(X+f(g,v,u))%M;
    }
    return r;
}
signed main() {
    I T;
    cin>>T;
    while(T--) {
        I n;
        cin>>n;
        Graph g(n);
        REP(i,n-1) {
            int u,v;
            cin>>u>>v,u--,v--;  
            g[u].P(v);
            g[v].P(u);
        }
        Graph h(n);
        REP(i,n-1) {
            I u,v;
            cin>>u>>v,u--,v--;  
            h[u].P(v);
            h[v].P(u);
        }
        if(f(g,0,-1)==f(h,0,-1)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}