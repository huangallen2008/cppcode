#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define vi vector<int>
#define vp vector<pii>
#define vvi vector<vi>
#define ykh mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
#define __lg(x) 63-__builtin_clzll(x)
#define pow2(x) (1LL<<x)
void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef local
void CHECK();
void setio(){
    freopen("/Users/iantsai/cpp/input.txt","r",stdin);
    freopen("/Users/iantsai/cpp/output.txt","w",stdout);
}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
void setio(){}
#define debug(x...)
#endif
#define TOI_is_so_de ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);setio();
const int mxn = 1e5 + 5, inf = 1e15;
int n, m, cnt;
struct DSU{
    int to[mxn], num[mxn];
    void init(){
        for(int i = 0; i < mxn; i++){
            to[i] = i;
            num[i] = 1;
        }
    }
    int find(int x){
        return x == to[x] ? x : to[x] = find(to[x]);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        if(num[x] > num[y]) swap(x, y);
        num[y] += num[x];
        to[x] = y;
        cnt--;
        return 1;
    }
}d;
struct segtree{
    struct node{
        pii mn, smn;
    }seg[4 * mxn];
    int tag[4 * mxn];
    void upd(int id, int v){
        seg[id].mn.F += v;
        seg[id].smn.F += v;
        tag[id] += v;
    }
    #define L seg[id * 2]
    #define R seg[id * 2 + 1]
    void init(){
        memset(tag, 0, sizeof(tag));
        build(1, n, 1);
    }
    void push(int id){
        upd(id * 2, tag[id]);
        upd(id * 2 + 1, tag[id]);
        tag[id] = 0;
    }
    void pull(int id){
        if(L.mn < R.mn){
            seg[id].mn = L.mn;
            if(d.find(R.mn.S) == d.find(L.mn.S)){
                if(d.find(L.mn.S) == d.find(L.smn.S)) seg[id].smn = R.smn;
                else seg[id].smn = min(L.smn, R.smn);
            }
            else{
                if(d.find(L.mn.S == d.find(L.smn.S))) seg[id].smn = R.mn;
                seg[id].smn = min(L.smn, R.mn);
            }
        }
        else{
            seg[id].mn = R.mn;
            if(d.find(L.mn.S) == d.find(R.mn.S)){
                if(d.find(R.mn.S) == d.find(R.smn.S)) seg[id].smn = L.smn;
                else seg[id].smn = min(L.smn, R.smn);
            }
            else{
                if(d.find(R.mn.S) == d.find(R.smn.S)) seg[id].smn = L.mn;
                else seg[id].smn = min(R.smn, L.mn);
            }
        }
    }
    void build(int l, int r, int id){
        tag[id] = 0;
        if(l == r) {
            seg[id].mn = {0, l};
            seg[id].smn = {1e18, l};
            return;
        }
        int mm = l + r >> 1;
        build(l, mm, id * 2);
        build(mm + 1, r, id * 2 + 1);
        pull(id);
    }
    void modify(int l, int r, int id, int ql, int qr, int v){
        if(qr < l or r < ql){
            return;
        }
        if(ql <= l and r <= qr){
            upd(id, v);
            return;
        }
        int mm = l + r >> 1;
        push(id);
        modify(l, mm, id * 2, ql, qr, v);
        modify(mm + 1, r, id * 2 + 1, ql, qr, v);
        pull(id);
    }
}tr;
void solve(){
    cin >> n >> m;
    d.init();
    vector<array<int, 3>>in[mxn];
    for(int i = 1; i <= m; i++){
        int a, b, c, d, w;
        cin >> a >> b >> c >> d >> w;
        in[a].pb({c, d, w});
        in[b + 1].pb({c, d, -w});
        in[c].pb({a, b, w});
        in[d + 1].pb({a, b, -w});
    }
    cnt = n;
    int ans = 0;
    vector<pii>opt(mxn);
    while(cnt > 1){
        tr.init();
        for(int i = 1;i <= n; i++){
            opt[i]={inf, 0};
        }
        for(int i = 1; i <= n; i++){
            for(auto [l, r, v] : in[i]){
                tr.modify(1, n, 1, l, r, v);
            }
            assert(d.find(i) >= 1);
            assert(d.find(i) <= n);
            if(d.find(tr.seg[1].mn.S) == d.find(i)){
                chmin(opt[d.find(i)], tr.seg[1].smn);
            }
            else{
                chmin(opt[d.find(i)], tr.seg[1].mn);
            }
        }
        for(int i = 1; i <= n; i++){
            if(d.find(i) != i) continue;
            if(opt[i].F > 2e11 or opt[i].S == 0) continue;
            debug(opt[i]);
            ans += d.merge(i, opt[i].S) * opt[i].F;
        }
    }
    cout << ans << '\n';
}
signed main(){
    TOI_is_so_de;
    int t = 1;
    while(t--){
        solve();
    }
    #ifdef local
    CHECK();
    #endif
}
/*
input:
 
*/
#ifdef local
void CHECK(){
    cerr << "\n[Time]: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    function<bool(string,string)> compareFiles = [](string p1, string p2)->bool {
        std::ifstream file1(p1);
        std::ifstream file2(p2);
        if(!file1.is_open() || !file2.is_open()) return false;
        std::string line1, line2;
        while (getline(file1, line1) && getline(file2, line2)) {
            if (line1 != line2)return false;
        }
        int cnta = 0, cntb = 0;
        while(getline(file1,line1))cnta++;
        while(getline(file2,line2))cntb++;
        return cntb - cnta <= 1;
    };
    bool check = compareFiles("output.txt","expected.txt");
    if(check) cerr<<"ACCEPTED\n";
    else cerr<<"WRONG ANSWER!\n";
}
#else
#endif

