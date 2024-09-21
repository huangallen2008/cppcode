#include<bits/stdc++.h>
using namespace std;
#define L int64_t
#define I int
#define G vector<vector<I>>
#define K(x) I x;cin>>x;
const L X=666666,M=1e9+9;
G g;
L f(I u,I fa) {
    L r=X;
    for(I v:g[u]) {
        if(v==fa) continue;
        r=r*(X+f(v,u))%M;
    }
    return r;
}
signed main() {
    // I T;
    // cin>>T;
    K(T)
    while(T--) {
        I n;
        cin>>n;
        auto F=[&](){
            g=G(++n);
            for(int i=1;i<n;i++) {
                I u,v;
                cin>>u>>v,u--,v--;  
                g[u].push_back(v);
                g[v].push_back(u);
            }
            return f(0,0);
        };
        cout<<(F()==F()?"YES\n":"NO\n");
    }
    return 0;
}