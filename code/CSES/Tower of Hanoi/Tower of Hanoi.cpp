#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
void move1_2(int n);
void move1_3(int n);
void move2_3(int n);
void move2_1(int n);
void move3_1(int n);
void move3_2(int n);
void move1_2(int n) {
    if(n==0) return;
    move1_3(n-1);
    cout<<"1 2\n";
    move3_2(n-1);
}
void move1_3(int n) {
    if(n==0) return;
    move1_2(n-1);
    cout<<"1 3\n";
    move2_3(n-1);
}
void move2_3(int n) {
    if(n==0) return;
    move2_1(n-1);
    cout<<"2 3\n";
    move1_3(n-1);
}
void move2_1(int n) {
    if(n==0) return;
    move2_3(n-1);
    cout<<"2 1\n";
    move3_1(n-1);
}
void move3_1(int n) {
    if(n==0) return;
    move3_2(n-1);
    cout<<"3 1\n";
    move2_1(n-1);
}
void move3_2(int n) {
    if(n==0) return;
    move3_1(n-1);
    cout<<"3 2\n";
    move1_2(n-1);
}
void solve() {
    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    move1_3(n);
}
signed main() {
    IOS();
    solve();
    return 0;
}
