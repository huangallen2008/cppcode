#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
#define Vi vector<int>
#define Vpii vector<pii>
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define Graph vector<Vi>
#define Graphw vector<Vpii>
const int inf=(1ll<<60);
#ifdef LOCAL
#define op(x) cerr<<(#x)<<'='<<(x)<<", ";
#define ope(x) cerr<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {for(auto allen:x) cerr<<(allen)<<' ';cerr<<endl;}
#define entr cerr<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
#define iint signed
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
iint add_not(iint X);
iint add_and(iint X, iint Y);
iint add_or(iint X, iint Y);
iint add_xor(iint X, iint Y);
iint add_lshift(iint X, iint D);
iint add_rshift(iint X, iint D);

void construct_logic(const std::string &s, signed K) {
    int k=K;
    int id=0,id2=0,_id2;
    id2=add_not(0);
    int _id=id;
    int R=SZ(s);
    _id2=id2;
    int nowid=0;
        int T=8;
    if(SZ(s)<T) {
        int fir=1,fir2=1;
        if(s[0]=='1') {
            fir=0;
        }else fir2=0;
        for(int i=1;i<SZ(s);i++) {
            if(s[i]=='1') {
                if(fir) {
                    id=add_lshift(id,i);
                    fir=0;
                }
                else {
                    int iid=add_lshift(_id,i);
                    id=add_and(id,iid);
                    // op(id)op(i)ope(iid)
                }
            }else {
                if(fir2) {
                    id2=add_lshift(id2,i);
                    ope(id2)
                    fir2=0;
                }
                else {
                    int iid=add_lshift(_id2,i);
                    id2=add_and(id2,iid);
                }
            }
        }
        if(!fir2&&!fir)id=add_and(id,id2);
        else if(!fir2) id=id2;
        nowid=id;
    }else {
        Vi cnt(1<<T);
        for(int i=0;i<R;i+=T) {
            if(i+T-1>=R) i=R-T;
            int tid=0;
            for(int j=i+T-1;j>=i;j--) tid=tid*2+(s[j]=='1');
            cnt[tid]++;
        }

        Vi lids(2); lids[0]=_id2,lids[1]=_id;
        Vi lids2(2); 
        lids2[0]=add_lshift(_id2,1);
        lids2[0]=add_lshift(_id2,1);
        Vi ids=lids;
        for(int K=2;K<=T;K*=2) {
            ids=Vi(1<<K);
            REP(i,1<<K) {
                if(K==T&&cnt[i]==0) continue;
                int nid=lids[i&((1<<(K>>1))-1)];
                int nid2=lids[i>>(K>>1)];
                // int tt=
                // if(i>>(K-1)&1) {
                    nid=add_and(nid,add_lshift(nid2,K>>1));
                // }else {
                //     nid=add_and(nid,tt2);
                // }
                ids[i]=nid;
            }
            // oparr(ids)
            if(K<T)swap(lids,ids);
        }
    nowid=-1;
    for(int i=0;i<R;i+=T) {
        if(i+T-1>=R) i=R-T;
        int tid=0;
        for(int j=i+T-1;j>=i;j--) tid=tid*2+(s[j]=='1');
        if(nowid==-1) {
            nowid=ids[tid];
        }else {
        int tt=add_lshift(ids[tid],i);
        nowid=add_and(nowid,tt);
        }
    }
    }
    // int tt=add_lshift(id2,R);id2=add_and(id2,tt);
    // tt=add_lshift(id2,R);id2=add_and(id2,tt);
    // if(!fir){
        ope("o1")
        int now=1;
        while(now*2<k) {
            int lid=nowid;
            nowid=add_lshift(nowid,now*R);
            ope(now)
            nowid=add_and(nowid,lid);
            now<<=1;
        }
        if(now<k){
            int lid=nowid;
            nowid=add_lshift(nowid,R*(k-now));
            ope(k-now)
            nowid=add_and(nowid,lid);
        }
    // }
    // if(!fir2){
    //     ope("o2")
    //     int now=1;
    //     while(now*2<k) {
    //         int lid=id2;
    //         id2=add_lshift(id2,R*now);
    //         id2=add_and(id2,lid);
    //         now<<=1;
    //     }
    //     if(now<k){
    //         int lid=id2;
    //         id2=add_lshift(id2,R*(k-now));
    //         id2=add_and(id2,lid);
    //     }
    // }
    // op(id)ope(id2)
    
}
