#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC target("avx2,popcnt")
#pragma GCC optimize("O3,unroll-loops,fast-math")
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
long double mn=10000;
int nowa=0,nowb=0,nowc=0;
void solve(int n,int l) {
    vector<int> a;
    int x=1,y=1,z=1,k=0;//x:i_t y:j_t z:k_t
    while(1) {
        if(((long long)y*(y-1)>>1)+z<=l) {
            k++;
            a.push_back(x);
        }
        //if(x>=n) break;
        if(y>=l) break;
        if(((long long)(x+1)*(x+2)>>1)<l) {
            x=y=z=x+1;
            continue;
        }
        z-=l;
        while(1) {
            if(y<1) y+=x,z+=x;
            else if(z<1) z+=y-1,y--;
            else break;
        }
        x++,y++,z++;
    }
    // for(int i=0;i<a.size();i++) cout<<a[i]<<' ';cout<<'\n';
    int maxai=(l-1)*(log(l-1)+(long double)1/(l*2-2)+0.5772156649);
    cout<<l<<' '<<a.back()<<" "<<maxai<<" "<<(a.back()<=maxai?"YES":"NO")<<endl;
    if(maxai<=mn*a.back()) {
        mn=(long double)maxai/a.back();
        nowa=a.back(),nowb=maxai,nowc=l;
    }
    // if(a.back()>maxai) {
    //     cout<<"find!"<<endl;
    //     cout<<l<<endl;
    // }
    // cout<<"I("<<n<<","<<l<<") = "<<k<<endl;
}
signed main() {
    IOS();
    int n,l;
    while(cin>>n>>l) {
        solve(n,l);
    }
    // cin>>n;
    // for(int i=4000;i<=n;i++) {
    //     solve(1,i);
    // } 
    cout<<fixed<<setprecision(15)<<mn<<'\n';
    cout<<nowa<<' '<<nowb<<' '<<nowc<<'\n';
    return 0;
}
