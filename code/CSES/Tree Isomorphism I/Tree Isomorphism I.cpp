#include<bits/stdc++.h>
using namespace std;
#define L int64_t
#define I int
#define G vector<vector<I>>
#define K(x) I x;cin>>x;
L X=666666,M=1e9+9;
G g;
L f(I u,I fa) {
    L r=X;
    for(I v:g[u]) {
        if(v==fa) continue;
        r=r*(X+f(v,u))%M;
    }
    return r;
}
I main() {
    K(T)
    while(T--) {
        K(n)
        auto F=[&](){
            g=G(++n);
            for(int i=2;i<n;i++) {
                K(u)K(v) 
                g[u].push_back(v);
                g[v].push_back(u);
            }
            return f(1,1);
        };
        cout<<(F()==F()?"YES\n":"NO\n");
    }
    return 0;
}