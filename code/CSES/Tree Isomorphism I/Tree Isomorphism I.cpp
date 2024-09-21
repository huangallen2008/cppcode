#include<bits/stdc++.h>
using namespace std;
#define L int64_t
#define I int
#define REP(i,n) for(I i=0;i<(n);i++)
#define P push_back
#define Graph vector<vector<I>>
const L X=666666,M=1e9+9;
Graph g;
L f(I u,I fa) {
    L r=X;
    for(I v:g[u]) {
        if(v==fa) continue;
        r=r*(X+f(v,u))%M;
    }
    return r;
}
signed main() {
    I T;
    cin>>T;
    while(T--) {
        I n;
        cin>>n;
        auto F=[&](){
            g=Graph(n);
            REP(i,n-1) {
                I u,v;
                cin>>u>>v,u--,v--;  
                g[u].P(v);
                g[v].P(u);
            }
            return f(0,0);
        };
        cout<<(F()==F()?"YES\n":"NO\n");
    }
    return 0;
}