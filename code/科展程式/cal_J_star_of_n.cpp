#include<bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2") 
#pragma GCC optimize("O3,unroll-loops,fast-math")
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
void solve(int n,int l) {
    vector<int> a;
    int x=1,y=1,z=1,k=0;//x:i_t y:j_t z:k_t
    while(1) {
        if(((long long)y*(y-1)>>1)+z<=l) {
            k++;
            a.push_back(x);
        }
        if(x>=n) break;
        if(((long long)(x+1)*(x+2)>>1)<l) {
            x=y=z=x+1;
            continue;
        }
        x++,y++,z+=l+1;
        while(1) {
            if(x<y) y-=x;
            else if(y<z) z-=y,y++;
            else break;
        }
    }
    for(int i=0;i<a.size();i++) cout<<a[i]<<' ';cout<<'\n';
    cout<<"J("<<n<<","<<l<<") = "<<k<<endl;
}
signed main() {
    IOS();
    int n,l;
    while(cin>>n>>l) {
        solve(n,l);
    }
    return 0;
}
