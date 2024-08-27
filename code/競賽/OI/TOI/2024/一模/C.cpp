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
    const int maxc=(59+maxb)/maxb;
    const int maxa=(1<<maxb);
    bitset<maxn> lt[maxc][maxa+1][maxn];//60  15*16
}

void initialize(int _n,const std::vector<std::pair<int, int>> segments) {
    n = _n;
    for(auto &[u,v]:segments) {
        lt[0][1][u][v]=1;
    }
    for(int t=2;t<maxa;t++) {
        REP1(j,n) {
            REP1(k,n) {
                if(lt[0][t-1][j][k]) lt[0][t][j]|=lt[0][1][k];
            }
        }
    }
    for(int i=1;i<maxc;i++) {
        REP1(j,n) {
            REP1(k,n) {
                if(lt[i-1][maxa-1][j][k]) lt[i][1][j]|=lt[i-1][1][k];
            }
        }
        for(int t=2;t<maxa;t++) {
            REP1(j,n) {
                REP1(k,n) {
                    if(lt[i][t-1][j][k]) lt[i][t][j]|=lt[i][1][k];
                }
            }
        }
    }
}

bool has_route(int s, int t, long long kd) {
    bitset<maxn> an;
    an[s]=1;
    for(int i=0,l=0;i<maxc;i++,l+=maxc) {
        int k=(kd>>l)&(maxa-1);
        if(k>0) {
            bitset<maxn> tmp;
            REP1(j,n) if(an[j]) tmp|=lt[i][k][j];
            an=tmp;
        }
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

