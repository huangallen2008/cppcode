#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt,sse4")
#define ll long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define ALL(x) (x).begin(),(x).end()

namespace {
    int n;
    const int lgv=60;
    const int maxn=260;
    const int maxb=10;
    const int maxc=39;
    const int maxa=0;
    bitset<maxn> lt[maxc][maxn];
    bitset<maxn> lt2[maxc][maxn];
}

void initialize(int _n,const std::vector<std::pair<int, int>> segments) {
    n = _n;
    for(auto &[u,v]:segments) {
        lt[0][u][v]=1;
        lt2[0][v][u]=1;
    }
    for(int i=1;i<maxc;i++) {
        REP1(j,n) {
            bitset<maxn> tmp;
            REP1(k,n) {
                if(lt[i-1][j][k]) tmp|=lt[i-1][k];
            }
            REP1(k,n) {
                if(tmp[k]) lt[i][j]|=lt[i-1][k];
            }
            tmp=0;
            REP1(k,n) {
                if(lt2[i-1][j][k]) tmp|=lt2[i-1][k];
            }
            REP1(k,n) {
                if(tmp[k]) lt2[i][j]|=lt2[i-1][k];
            }
        }
    }
}

bool has_route(int s, int t, long long kd) {
    bitset<maxn> an;
    an[s]=1;
    int n0=0;
    for(int i=0;i<maxc;i++) {
        int k=kd%3+n0;
        n0=0;
        if(k==1) {
            bitset<maxn> tmp;
            REP1(j,n) if(an[j]) tmp|=lt[i][j];
            swap(tmp,an);
        }
        else if(k==2) {
            bitset<maxn> tmp;
            REP1(j,n) if(an[j]) tmp|=lt2[i][j];
            swap(tmp,an);
            n0++;
        }
        else if(k==3) n0++;
        kd/=3;
    }
    return an[t];
}
//signed main() {}

//int main() {
//    int n, m, q;
//    scanf("%d %d %d", &n, &m, &q);
//    std::vector<std::pair<int, int>> segments(m);
//    for (auto &[u, v] : segments)
//        scanf("%d %d", &u, &v);
//    initialize(n, segments);
//    for (int i = 0; i < q; i++) {
//        int s, t;
//        long long k;
//        scanf("%d %d %lld", &s, &t, &k);
//        if (has_route(s, t, k))
//            puts("true");
//        else
//            puts("false");
//    }
//    return 0;
//}

