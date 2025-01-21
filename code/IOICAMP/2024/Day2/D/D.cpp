#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
signed main() {
    IOS();
    string s;
    cin>>s;
    int n=s.size();
    vector<int> cnt(3);
    REP(i,n) {
        cnt[(s[i]-'0')%3]++;
    }
    if(cnt[1]==1&&cnt[2]==0) {
        cout<<"NO\n";
        exit(0);
    }
    if(cnt[1]==0&&cnt[2]==1) {
        cout<<"NO\n";
        exit(0);
    }
    vector<int> tcnt=cnt;
    cnt[0]%=3;
    cnt[1]%=3;
    cnt[2]%=3;
    vector<int> mi(3);
    if(cnt[1]==cnt[2]+1) {
        if(tcnt[2]>0)mi[2]=1;
        else mi[1]=2;
    }
    else if(cnt[2]==cnt[1]+1) {
        if(tcnt[1]>0)mi[1]=1;
        else mi[2]=2;
    }
    else if(cnt[1]==cnt[2]) {

    }
    else if(cnt[1]==cnt[2]+2) {
        mi[1]=1;
    }
    else if(cnt[1]==cnt[2]-2) {
        mi[2]=1;
    }
    REP(i,n) {
        int t=(s[i]-'0')%3;
        if(mi[t]>0) {
            cout<<"-"<<s[i];
            mi[t]--;
        }
        else cout<<"+"<<s[i];
    }
    cout<<'\n';
    return 0;
}
