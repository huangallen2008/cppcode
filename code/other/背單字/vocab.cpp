#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct voc {
    int id;
    string en;
    string aa;
    string cn;
    int cnt;
    int sc;
};
void opt_voc(voc a) {
    cout<<a.en<<" "<<a.aa<<" "<<a.cn<<endl;
}
bool so(voc a,voc b) { return a.sc>b.sc; }
signed main() {
    ofstream odata;
    // freopen("voc1.txt","r",stdin);
    int id;
    string en,aa,cn;
    char ch;
    vector<voc> v;
    while(cin>>id) {
        if(id==-1) break;
        cin>>ch>>en>>aa;
        int cnt=1;
        while(aa[0]!='(') {
            en=en+" "+aa;
            cin>>aa;
            cnt++;
        }
        cin>>cn;
        // op(id)op(ch)op(en)op(aa)ope(cn)
        v.pb({id,en,aa,cn,cnt,3});
    }
    // for(auto [s1,s2,s3,s4]:v) {
    //     op(s1)op(s2)op(s3)ope(s4)
    // }
    system("cls");
    int vn=v.size();
    vector<int> wa={0,2,4,6,7,7,8};
    odata.open("data.txt");
    odata<<"ok";
    ope("ok")
    int vision=1;
    while(1) {
        // sort(ALL(v),so);
        REP(i,v.size()) {
            // cerr<<i<<endl;
            odata<<v[i].id<<' '<<v[i].en<<' '<<v[i].aa<<' '<<v[i].cn<<' '<<v[i].cnt<<' '<<v[i].sc<<'\n';
        }odata<<"vision "<<(vision++)<<"\n-------------------\n";
        vector<int> ids;
        for(auto vo:v) REP(i,vo.sc) ids.pb(vo.id);
        cout<<"1:no,2:yes\n";
        int opt;
        cin>>opt;
        system("cls");
        if(opt==0) {
            for(auto vo:v) {
                cout<<"{"<<vo.id<<":"<<vo.sc<<"} ";
            }cout<<endl;
        }
        if(opt==1||opt==2) {
            cout<<"number:(all:"<<v.size()<<")\n";
            int n;
            cin>>n;
            system("cls");
            REP1(i,n) {
                int id=ids[rd(0,ids.size()-1)];
                re:
                cout<<"("<<i<<"/"<<n<<")\n";
                cout<<v[id].cn<<" "<<v[id].aa<<endl;
                if(opt==2) {
                    cout<<v[id].en[0]<<endl;
                }
                string san,tt;
                REP(rd,v[id].cnt) {
                    cin>>tt;
                    san+=tt+" ";
                }
                san.pop_back();
                if(san==v[id].en) {
                    system("cls");
                    cout<<"("<<i<<"/"<<n<<")\n";
                    cout<<v[id].cn<<" "<<v[id].aa<<endl;
                    if(opt==2) {
                        cout<<v[id].en[0]<<endl;
                    }
                    v[id].sc=max(v[id].sc-1,1ll);
                    cout<<"GOOD!\n";
                    opt_voc(v[id]);
                    system("pause");
                    system("cls");
                }
                else {
                    system("cls");
                    cout<<"("<<i<<"/"<<n<<")\n";
                    cout<<v[id].cn<<" "<<v[id].aa<<endl;
                    if(v[id].sc>6) v[id].sc++;
                    else v[id].sc=wa[v[id].sc];
                    if(opt==2) {
                        cout<<v[id].en[0]<<endl;
                    }
                    cout<<"NO!\n";
                    opt_voc(v[id]);
                    system("pause");
                    system("cls");
                    goto re;
                }
            }
        }
    }
    return 0;
}