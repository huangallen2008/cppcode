#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, n+1)
#define RREP(i, n) for (int i = (n)-1; i >= 0; i--)
#define RREP1(i, n) for (int i = (n); i >= 1; i--)
#define pii pair<int, int>
#define f first
#define s second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)((x).size())
#define pb push_back
#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const ll maxn = 5e3+5;
const ll maxm = 1e4+5;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

int dp[205][maxm][55];
int n, c, k;
vector<pii> V;

bool cmp(pii a, pii b){
    if (a.f == b.f) return a.s > b.s;
    return a.f < b.f;
}

void inp(){
	n=rd(1,200),c=rd(1,20),k=1;
    // cin>>n>>c>>k;
    V = vector<pii> (n+1);
    REP1(i, n) V[i].f=rd(1,20),V[i].s=rd(1,20);//cin>>V[i].f>>V[i].s;
    // REP1(i, n) cin>>V[i].f>>V[i].s;
}

int run(){
    REP1(i, n+1){
        REP(j, c+1){
            REP(x, k+1){
                dp[i][j][x] = 0;
            }
        }
    }
    vector<pii> vc = V;
    sort(ALL(vc), cmp);
    RREP1(i, n){
        REP(j, c+1){
            REP(x, k+1){
                dp[i][j][x] = dp[i+1][j][x];
                if (j >= 1) dp[i][j][x] = max(dp[i][j][x], dp[i][j-1][x]);
                if (x >= 1) dp[i][j][x] = max(dp[i][j][x], dp[i][j][x-1]);
                if (j >= vc[i].f) dp[i][j][x] = max(dp[i][j][x], dp[i+1][j-vc[i].f][x]+vc[i].s);
                if (x >= 1) dp[i][j][x] = max(dp[i][j][x], dp[i+1][j][x-1]+vc[i].s);
            }
        }
    }

    int ans = dp[1][c][0];

    int lb = 0, sm = 0;
    vector<int> oo;
    REP1(i, n){
        lb += vc[i].f;
        sm += vc[i].s;
        if (lb > c) break;
        oo.pb(vc[i].s);
        sort(ALL(oo));

        int tsm = sm;
        REP(j, min(k, i)){
            tsm -= oo[j];
            ans = max(ans, tsm + dp[i+1][c-lb][j+1]);
        }
    }
	#define chmax(x,y) x=max(x,y)
    auto rrun=[&]() {
        vector<int> ddp(c+1);
        REP1(i,n) {
            for(int j=c;j>=V[i].f;j--) chmax(ddp[j],ddp[j-V[i].f]+V[i].s);
        }
        // oparr(dp)
        return ddp[c];
    };
	int an=rrun();
    REP1(i,n) {
        REP1(j,i) {
			
			// REP1(i2,n) {REP1(j2,i2) {
            swap(V[i].s,V[j].s);
            // swap(V[i2].s,V[j2].s);
            chmax(an,rrun());
            // swap(V[i2].s,V[j2].s);
            swap(V[i].s,V[j].s);
        // }}
		}
    }
	// cout<<ans<<' '<<an<<endl;
    return ans==an;
}
/*
int run2(){
    REP1(i, n+1){
        REP(j, c+1){
            REP(x, k+1){
                dp[i][j][x] = 0;
            }
        }
    }
    vector<pii> vc = V;

    RREP1(i, n){
        REP(j, c+1){
            REP(z, k+1){
                dp[i][j][z] = dp[i+1][j][z];
                if (j >= 1) dp[i][j][z] = max(dp[i][j][z], dp[i][j-1][z]);
                if (z >= 1) dp[i][j][z] = max(dp[i][j][z], dp[i][j][z-1]);
                if (j >= vc[i].f) dp[i][j][z] = max(dp[i][j][z], dp[i+1][j-vc[i].f][z] + vc[i].s);
                if (z >= 1) dp[i][j][z] = max(dp[i][j][z], dp[i+1][j][z-1] + vc[i].s);
            }
        }
    }



    int ans = dp[1][c][0];

    int lb = 0, sm = 0;
    vector<int> oo;
    REP1(i, n){
        lb += vc[i].f;
        sm += vc[i-1].s;
        if (lb > c) break;

        ans = max(ans, dp[i+1][c-lb][1]+sm);
    }
    return ans;
}
*/

signed main(){
	// freopen("in.txt","r",stdin);
	int T=100;
	// cin>>T;
	while(T--) {
    inp();
    if(!run()) {
		cout<<n<<' '<<c<<' '<<k<<'\n';
		REP1(i,n) cout<<V[i].f<<' '<<V[i].s<<'\n';
		cout<<"WA\n";
		break;
	}
	}
}
/*
5 10 5
2 1
3 1
5 3
6 101
7 100
*/
