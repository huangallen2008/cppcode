#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Vi vector<int> 
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#ifdef LOCAL_
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxv=1e5+5;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) { return pw(x,mod-2); }
signed main() {
    Vi isp(maxv,1);
    isp[0]=isp[1]=0;
    for(int i=2;i*i<maxv;i++) {
        if(isp[i]) {
            for(int j=i+i;j<maxv;j+=i) isp[j]=0;
        }
    }
    int w,h;
    cin>>w>>h;

            // {
            //     int an0=0;
            //     REP(i,w) REP(j,h) {
            //         if(i==0&&j==0) continue;
            //         an0+=(w-i)*(h-j)*(__gcd(i,j)-1);
            //     }
            //     ope(an0)
            //     int A=30*29*28/6;
            //     ope(A)
            // }

    Vi v1(maxv);
    REP1(i,maxv-1) v1[i]=(((w-1)/i)*((h-1)/i))%mod;
    for(int i=2;i<maxv;i++) if(isp[i]) {
        for(int j=1;j*i<maxv;j++) (v1[j]-=v1[j*i])%=mod;
    }
    int val1=0; REP(i,maxv) (val1+=(i-1)*v1[i])%=mod;
    Vi v2(maxv);
    REP1(i,maxv-1) {
        int t=(w-1)/i;
        v2[i]=t*(t+1)%mod*inv(2)%mod*i%mod*((h-1)/i)%mod;
    }
    for(int i=2;i<maxv;i++) if(isp[i]){
        for(int j=1;j*i<maxv;j++) (v2[j]-=v2[j*i])%=mod;
    }
    int val2=0; REP(i,maxv) (val2+=(i-1)*v2[i])%=mod;
    
    Vi v3(maxv);
    REP1(i,maxv-1) {
        int t=(h-1)/i;
        v3[i]=t*(t+1)%mod*inv(2)%mod*i%mod*((w-1)/i)%mod;
    }
    for(int i=2;i<maxv;i++) if(isp[i]){
        for(int j=1;j*i<maxv;j++) (v3[j]-=v3[j*i])%=mod;
    }
    int val3=0; REP(i,maxv) (val3+=(i-1)*v3[i])%=mod;
    
    // REP(i,5) cout<<v3[i]<<' ';entr/////////////////////////
    Vi v4(maxv); 
    REP1(i,maxv-1) {
        int t=(h-1)/i,t2=(w-1)/i;
        v4[i]=t*(t+1)%mod*inv(2)%mod*t2%mod*(t2+1)%mod*inv(2)%mod*i%mod*i%mod;
    }
    for(int i=2;i<maxv;i++) if(isp[i]){
        for(int j=1;j*i<maxv;j++) (v4[j]-=v4[j*i])%=mod;
    }
    int val4=0; REP(i,maxv) (val4+=(i-1)*v4[i])%=mod;
    
    op(val1)op(val2)op(val3)ope(val4)
    int an = (w*h)%mod*val1%mod-h*val2%mod-w*val3%mod+val4%mod;
    // an= (-w*w%mod*h%mod*h%mod) + (h*w%mod*(w-1)%mod*inv(2)%mod) + (w*h%mod*(h-1)%mod*inv(2)%mod) - (w*(w-1)%mod*h%mod*(h-1)%mod*inv(4)%mod) + (w*h%mod*val1%mod) - (h*val2%mod) - (w*val3%mod) + (val4%mod);
    ope(an)
    an=((w*h%mod*((w*h-1)%mod)%mod*((w*h-2)%mod)%mod*inv(6)%mod-w*h%mod*(h-1)%mod*(h-2)%mod*inv(6)%mod-h*w%mod*(w-1)%mod*(w-2)%mod*inv(6)%mod-2*an)%mod+mod)%mod;
    cout<<an<<'\n';
    return 0;
}
